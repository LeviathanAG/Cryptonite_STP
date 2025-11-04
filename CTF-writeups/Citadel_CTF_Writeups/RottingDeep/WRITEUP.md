# Rotting Deep

## Challenge
Given a Python script that encrypts the flag and the encrypted output.

## Analysis
The encryption process:
1. Convert flag to long integer using `bytes_to_long`
2. Convert to string
3. Shift each digit by KEY=3 (mod 10)

## Solution
Reverse the process:
1. Shift each digit back by 3 (mod 10)
2. Convert result to integer
3. Convert to bytes using `long_to_bytes`

```python
from Crypto.Util.number import *
from string import digits

out = "6895840967002953721051398351211751734500850509315790892845302801984496338433523326225010635779036738800318"
KEY = 3
decrypted = ""

for i in out:
    decrypted += digits[(int(i) - KEY) % 10]

flag_int = int(decrypted)
flag = long_to_bytes(flag_int)
print(flag.decode())
```

## Flag
`citadel{br0_r34lly_unr0tt3d_m3_b4ck_t0_l1f3}`
