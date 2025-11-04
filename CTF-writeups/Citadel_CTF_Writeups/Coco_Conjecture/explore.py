import socket

HOST = "chall_citadel.cryptonitemit.in"
PORT = 61234

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.connect((HOST, PORT))

# Receive initial data
data = s.recv(4096).decode()
print(data)

# Keep receiving to see what the challenge asks
for i in range(5):
    try:
        data = s.recv(4096).decode()
        if data:
            print(data)
    except:
        break

s.close()
