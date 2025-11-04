import os, sys, base64, itertools

candidates = ["usercomment.raw", "copyright.raw", "usercomment.txt", "copyright.txt"]

def load_first():
    for fn in candidates:
        if os.path.exists(fn):
            b = open(fn, "rb").read()
            try:
                s = b.decode("utf-8")
            except Exception:
                s = b.decode("latin1")
            return s, fn
    print("No files found. Run exiftool -UserComment -b and -Copyright -b first.")
    sys.exit(1)

s, fname = load_first()
print(f"Loaded {fname} ({len(s)} chars).")

# collect characters that are nonprintable / zero-width / high private-use
zw_candidates = []
for c in s:
    cp = ord(c)
    # heuristics: invisible / zero-width / private-use / high plane
    if c.isspace() and c != ' ':
        # catches U+200B ZWSP etc (they are considered whitespace by some methods)
        zw_candidates.append(c)
    elif cp in (0x200B,0x200C,0x200D,0xFEFF,0x2060,0x180E):
        zw_candidates.append(c)
    elif cp >= 0xE000 or cp >= 0xF0000 or cp >= 0x10000:  # private use or high plane
        zw_candidates.append(c)

zw_seq = zw_candidates
print("Found", len(zw_seq), "interesting chars in metadata.")
if len(zw_seq) == 0:
    print("No suspicious/invisible/high-codepoint chars found. Printing text for manual inspection:")
    print(s)
    sys.exit(0)

# Unique set in order of appearance
unique = []
for c in zw_seq:
    if c not in unique:
        unique.append(c)
print("Unique symbols found (in appearance order):")
for c in unique:
    print(f"U+{ord(c):04X}", end=" ")
print("\n")

# ---------- Strategy A: zero-width bit mapping (map unique symbols -> 0/1) ----------
def bits_to_bytes(bitstr, group):
    if len(bitstr) % group != 0:
        bitstr = bitstr + ('0' * (group - (len(bitstr) % group)))
    out = bytearray()
    for i in range(0, len(bitstr), group):
        out.append(int(bitstr[i:i+group], 2))
    return bytes(out)

def try_decode_bytes(b):
    results = []
    # try utf-8
    try:
        results.append(("utf-8", b.decode('utf-8')))
    except Exception:
        pass
    # latin1
    try:
        results.append(("latin1", b.decode('latin1')))
    except Exception:
        pass
    # base64
    try:
        dec = base64.b64decode(b, validate=True)
        try:
            results.append(("base64->utf8", dec.decode('utf-8')))
        except:
            results.append(("base64->bytes", dec))
    except Exception:
        pass
    # ascii hex
    try:
        h = b.decode('ascii')
        dec = bytes.fromhex(h)
        results.append(("hex->bytes", dec))
    except Exception:
        pass
    return results

printed = 0
if len(unique) <= 6:  # try mappings only if manageable
    # try all 2^n mappings of unique symbols to bits
    for assign in itertools.product('01', repeat=len(unique)):
        mapping = { unique[i]: assign[i] for i in range(len(unique)) }
        bitstr = ''.join(mapping[c] for c in zw_seq)
        for group in (8,7,4):
            b = bits_to_bytes(bitstr, group)
            decs = try_decode_bytes(b)
            if decs:
                print("=== Candidate (zw mapping) ===")
                print("mapping:", {f"U+{ord(k):04X}":v for k,v in mapping.items()})
                print("group bits:", group, " -> bytes len:", len(b))
                for t, out in decs:
                    print(f"[{t}] {out if isinstance(out,str) else out!r}")
                printed += 1

# ---------- Strategy B: private-use codepoint -> byte via base guesses ----------
bases = [0xE000, 0xF000, 0xF0000, 0x10000, 0x100000, 0x1F0000]
codepoints = [ord(c) for c in zw_seq]
for base in bases:
    mapped = []
    ok = True
    for cp in codepoints:
        val = cp - base
        if val < 0:
            ok = False
            break
        # map to 0..255 by modulo
        mapped.append(val % 256)
    if not ok:
        continue
    b = bytes(mapped)
    decs = try_decode_bytes(b)
    if decs:
        print("=== Candidate (base subtraction) ===")
        print(f"base: 0x{base:X}, bytes len: {len(b)}")
        for t, out in decs:
            print(f"[{t}] {out if isinstance(out,str) else out!r}")
        printed += 1

# ---------- Strategy C: cp % 256 fallback (raw) ----------
b = bytes([cp % 256 for cp in codepoints])
decs = try_decode_bytes(b)
if decs:
    print("=== Candidate (cp % 256) ===")
    for t, out in decs:
        print(f"[{t}] {out if isinstance(out,str) else out!r}")
    printed += 1

if printed == 0:
    print("No clear decodes found. Fallback: printing codepoints sequence for manual analysis:")
    print([f"U+{cp:04X}" for cp in codepoints])
    print("You can paste that into chat if you want me to try other custom heuristics.")
