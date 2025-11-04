from Crypto.Util.number import *
from string import digits

# Encrypted output
out = "6895840967002953721051398351211751734500850509315790892845302801984496338433523326225010635779036738800318"

# Decrypt by reversing the shift
KEY = 3
decrypted = ""

for i in out:
    decrypted += digits[(int(i) - KEY) % 10]

# Convert back to flag
flag_int = int(decrypted)
flag = long_to_bytes(flag_int)
print(flag.decode())
