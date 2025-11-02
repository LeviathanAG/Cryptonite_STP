
import math as m
import sympy as sp


p=101
q=313846144900241708687128313929756784551

n = 31698460634924412577399959706905435239651
e = 65537
c = 23648999580642514140599125257944114844209

print("n % c:", n%c)
y=p*q
print("p*q (usual m):", y)
print("given n:", n)
print("Are they equal?", y==n)
print("\nComparing 'usual m' and n:")
print("Difference (p*q - n):", y - n)

print(sp.isprime(p))
print(sp.isprime(q))
phi = (p-1)*(q-1)
print("phi:", phi)
d = pow(e, -1, phi)
print("d:", d)

print("Is n prime?", sp.isprime(n))


m_decrypted = pow(c, d, n)
print("\nDecrypted message:", m_decrypted)
print("Modulus n:       ", n)
print("\nIs m < n? (usual requirement)", m_decrypted < n)
print("Difference (n - m):", n - m_decrypted)
print("\nAs hex:", hex(m_decrypted))
try:
    flag = bytes.fromhex(hex(m_decrypted)[2:]).decode()
    print("As text:", flag)
except:
    print("Cannot decode as text")
    


k = n % c
print("n % c = k =", k)

for formula, val in [
    ("m_decrypted", m_decrypted),
    ("m + n", m_decrypted + n),
    ("m + k", m_decrypted + k),
    ("k", k),
    ("c - n", c - n),
    ("c % n", c % n),
]:
    hex_str = hex(val)[2:]
    if len(hex_str) % 2:
        hex_str = '0' + hex_str
    try:
        flag_bytes = bytes.fromhex(hex_str)
        text = flag_bytes.decode('utf-8', errors='ignore')
        if text.isprintable() and len(text) > 5:
            print(f"✓ {formula}: {text}")
    except:
        pass

k =8049461054281898436800834448961320395442

