# random stuff

## part 2 

part.py is very straight forward, on transformation reversal we get : `_1s_n0t_th4t_h4rd}`


# part 1

What the file exposes

* The script encrypts a known plaintext under AES-ECB using a key derived from seed: key = SHA256(long_to_bytes(seed)).
* It prints four LCG values: a, c, m and the truncated post-update state R, where R = state_after >> 20.
* The LCG update inside the class is: state_after = (a * seed**65537 + c) % m. The printed value is state_after shifted right by 20 bits (so the low 20 bits are hidden).

Why this leak is useful

* seed is only 50 bits long . Recovering seed gives the AES key directly.
* The script prints most of state_after (all but 20 low bits). That gives  only 2^20 possible low-bit pncs
* Because m is prime, exponentiation by 65537 is invertible on the multiplicative group modulo m.

High-level recovery procedure

1. Read the printed values: a, c, m and R 
   

2. For  k in [0, 2^20):
   a. Form a candidate full post-update state: candidate_state = (R << 20) | k.
   b. Rearrange the LCG update to isolate seed**65537:
   seed ** 65537 ≡ (candidate_state - c) * a^{-1} (mod m).

3. Compute t = (state - c) * a^{-1} mod m.

4. Compute a modular 65537-th root: candidate_seed = pow(t, d, m), where d is the multiplicative inverse of 65537 modulo (m-1). This works because m is prime and the multiplicative group has order m-1.
5. Enforce seed size: discard candidate_seed >= 2^50 (seed must be 50 bits).
6. Derive key = SHA256(long_to_bytes(candidate_seed)) and try to decrypt the ciphertext with AES-ECB. If the decryption decrypts to have v1t{ i stopped.

soln : 

```py


from hashlib import sha256
from Crypto.Cipher import AES
from Crypto.Util.Padding import unpad
from Crypto.Util.number import long_to_bytes

enc_hex = "e6979fb9c93ede1e85bbeb51224969da271fae19054d01e16b7a538f69f48c7a"
enc = bytes.fromhex(enc_hex)

a = 958181900694223
c = 1044984108221161
m = 675709840048419795804542182249
R = 176787694147066159797379  # lcg.next() out


inv_a = pow(a, -1, m)
d = pow(65537, -1, m - 1)

def long_to_bytes_min(n):
    if n == 0:
        return b"\x00"
    return long_to_bytes(n)

def looks_printable(b):
    
    if len(b) == 0:
        return False
    printable = sum(1 for x in b if 32 <= x < 127)
    return (printable / len(b)) >= 0.7

def try_decrypt_with_seed(seed):
    key = sha256(long_to_bytes_min(seed)).digest()
    cipher = AES.new(key, AES.MODE_ECB)
    pt = cipher.decrypt(enc)
    # try unpad
    try:
        up = unpad(pt, 16)
        if looks_printable(up):
            return ("unpad_printable", up.decode(errors="replace"), key)
    except Exception:
        pass
    # if not padded  check raw
    if looks_printable(pt):
        return ("raw_printable", pt.decode(errors="replace"), key)
    
    if b"v1t{" in pt or b"v1t{" in (pt or b""):
        return ("raw_contains_v1t", pt.decode(errors="replace"), key)
    if b"flag" in pt.lower():
        return ("raw_contains_flag", pt.decode(errors="replace"), key)
    return None

limit = 1 << 20
found = 0
for k in range(limit):
    if k % 100000 == 0 and k != 0:
        print(f" tried {k} / {limit} ...")
    new_state = (R << 20) | k
    # compute t = a^{-1} * (new_state - c) mod m
    t = (new_state - c) * inv_a % m
    # candidate seed = t^d mod m
    candidate_seed = pow(t, d, m)
    
    res = try_decrypt_with_seed(candidate_seed)
    if res:
        kind, text, key = res
        found += 1
        
        print("derived key", key.hex())
        print("plaintext =", text)
      
```

output : 
```bash
derived key  = 2fa0d015c47e269e94242cb920522c7a215000c80901394d11188d49856607e9
plaintext  = v1t{Pseud0_R4nd0m_G3ner4t0r
```


- flag : `v1t{Pseud0_R4nd0m_G3ner4t0r_1s_n0t_th4t_h4rd}`




