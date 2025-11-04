from pwn import *

print(cyclic(1000))
with open("cyclic_gen.bin", "wb") as f:
    f.write(cyclic(1000))
    f.close()

print("Cyclic pattern of length 1000 written to cyclic_gen.bin")
