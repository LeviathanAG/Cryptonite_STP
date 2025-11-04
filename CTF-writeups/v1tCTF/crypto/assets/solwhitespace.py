data = bytes.fromhex("e25f9cf8b7c23f39f40f9c7e5be45f16fa07c63f31f98fa07e5be45f0cf8b7cbbf39f22f987c13")
rev = bytes(int(f"{b:08b}"[::-1], 2) for b in data)
print(rev.hex())
