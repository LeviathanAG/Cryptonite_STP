import socket
import re

HOST = "chall_citadel.cryptonitemit.in"
PORT = 61234

def collatz_steps(n):
  
    steps = 0
    while n != 1:
        if n % 2 == 0:
            n = n // 2
        else:
            n = 3 * n + 1
        steps += 1
    return steps

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.settimeout(2)
s.connect((HOST, PORT))


buffer = ""
while True:
    try:
        chunk = s.recv(4096).decode()
        buffer += chunk
        print(chunk, end='', flush=True)
        if "Your answer:" in chunk:
            break
    except socket.timeout:
        break


for round_num in range(1, 270):
    
    match = re.search(r'Round \d+: (\d+)', buffer)
    if match:
        n = int(match.group(1))
        
     
        steps = collatz_steps(n)
        print(f"{steps}")
        
       
        s.sendall(f"{steps}\n".encode())
        

        buffer = ""
        try:
            chunk = s.recv(4096).decode()
            buffer += chunk
            print(chunk, end='', flush=True)
        except socket.timeout:
            break
    else:
        break


try:
    s.settimeout(1)
    final = s.recv(4096).decode()
    print(final, flush=True)
except:
    pass

s.close()
