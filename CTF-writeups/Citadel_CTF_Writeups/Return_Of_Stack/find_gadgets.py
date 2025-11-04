#!/usr/bin/env python3

from pwn import *
import os

context.update(arch='amd64', os='linux')

# Load the binary
script_dir = os.path.dirname(os.path.abspath(__file__))
binary_path = os.path.join(script_dir, 'chal')
elf = ELF(binary_path)


# Create a ROP object
rop = ROP(elf)

# Find ret gadgets

ret_gadgets = rop.find_gadget(['ret'])
print(f"ret gadget: {hex(ret_gadgets.address) if ret_gadgets else 'Not found'}")




