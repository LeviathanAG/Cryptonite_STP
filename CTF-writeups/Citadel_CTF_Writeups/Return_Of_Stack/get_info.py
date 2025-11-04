#!/usr/bin/env python3

from pwn import *

context.update(arch='amd64', os='linux')

# Load the binary
import os
script_dir = os.path.dirname(os.path.abspath(__file__))
binary_path = os.path.join(script_dir, 'chal')
elf = ELF(binary_path)



print(f"Architecture: {elf.arch}")
print(f"Bits: {elf.bits}")
print(f"Endianness: {elf.endian}")
print(f"PIE enabled: {elf.pie}")
print(f"NX enabled: {elf.nx}")
print(f"Canary: {elf.canary}")
print()


# some address we might need ig
if 'win' in elf.symbols:
    win_addr = elf.symbols['win']
    print(f"win() address: {hex(win_addr)}")
else:
    print("win() not found in symbols")

if 'vuln' in elf.symbols:
    vuln_addr = elf.symbols['vuln']
    print(f"vuln() address: {hex(vuln_addr)}")
else:
    print("vuln() not found in symbols")

if 'main' in elf.symbols:
    main_addr = elf.symbols['main']
    print(f"main() address: {hex(main_addr)}")
else:
    print("main() not found in symbols")

