import os

# Read copyright.raw
with open('copyright.raw', 'rb') as f:
    s = f.read().decode('utf-8')

# Extract zero-width/special characters
zw = [c for c in s if ord(c) >= 0xE000]
print(f"Found {len(zw)} special chars in copyright.raw")

# Try different decoding strategies
# Strategy 1: Subtract 0xE000 and mod 256
decoded1 = bytes([(ord(c) - 0xE000) % 256 for c in zw])
print(f"\nDecoded (base 0xE000, mod 256): {decoded1}")
try:
    print(f"As ASCII: {decoded1.decode('ascii')}")
except:
    print(f"As Latin1: {decoded1.decode('latin1')}")

# Now do the same for usercomment.raw
print("\n" + "="*50)
with open('usercomment.raw', 'rb') as f:
    s = f.read().decode('utf-8')

zw = [c for c in s if ord(c) >= 0xE000 or ord(c) >= 0x1F000]
print(f"Found {len(zw)} special chars in usercomment.raw")

decoded2 = bytes([(ord(c) - 0xE000) % 256 for c in zw])
print(f"\nDecoded (base 0xE000, mod 256): {decoded2}")
try:
    print(f"As ASCII: {decoded2.decode('ascii')}")
except:
    print(f"As Latin1: {decoded2.decode('latin1')}")

# Let's check if it's base64 or hex
import base64
try:
    # Try base64 on both
    print("\n" + "="*50)
    print("Trying base64 decode on copyright:")
    b64_decoded = base64.b64decode(decoded1)
    print(f"Base64 decoded: {b64_decoded}")
    print(f"As ASCII: {b64_decoded.decode('ascii')}")
except Exception as e:
    print(f"Base64 decode failed: {e}")
