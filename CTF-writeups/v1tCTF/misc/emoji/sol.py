
import unicodedata

data = open(r"C:\ctf_writeups\v1tCTF\misc\emoji\a.txt", "r", encoding="utf-8").read()
vals = []

for ch in data:
    try:
        name = unicodedata.name(ch)
    except ValueError:
        continue
    if "VARIATION SELECTOR" in name:
        n = int(name.split('-')[-1])   
        vals.append(chr(n))

raw = ''.join(vals)
shifted = ''.join(chr(ord(c)-1) for c in raw)

print("raw   :", raw)
print("shift :", shifted)
