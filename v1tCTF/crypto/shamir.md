# shmair's secret

Shamir’s encryption is an enc algo where  one secret is divided into several parts so that no single piece reveals anything, but a few of them together can rebuild the original secret. It does this by turning the secret into a poly eqn, then giving each participant one coordinate from that equation as their share. Each share looks like a random number by itself, but when enough people combine their cts, the original secret appears again through a process called interpolation.

- Lagrange interpolation -  It takes any three of the shared points and finds the single curve that passes through all of them. Because polynomials are determined uniquely by enough points, the constant term of that curve will always be the original secret. The math involves computing a weighted sum of the y values, where the weights depend on the x positions of the shares. This process cancels out all the random parts and leaves only the hidden constant, which is the secret that was originally split.

- since we know we need 3 or more points we can use this algorithm

- code implementing interpolation -

```py
# reconstruct_shamir_integer.py
from fractions import Fraction
from itertools import combinations

def lagrange_zero(points):
    # points: list of (x:int, y:int)
    res = Fraction(0,1)
    for j,(xj,yj) in enumerate(points):
        lj = Fraction(1,1)
        for m,(xm,ym) in enumerate(points):
            if m==j: continue
            lj *= Fraction(-xm, xj - xm)
        res += Fraction(yj) * lj
    if res.denominator != 1:
        return None
    return res.numerator


shares = []
with open("shares.txt","r") as f:
    for line in f:
        line = line.strip()
        if not line: continue
        name, hx = line.split("-",1)
        shares.append((name, int(hx,16)))


for comb in combinations(range(len(shares)), 3):
    pts = [(i+1, shares[i][1]) for i in comb] 
    val = lagrange_zero(pts)
    if val is None:
        continue
    hx = format(val, "x")
    if len(hx) % 2:
        hx = "0" + hx
    try:
        b = bytes.fromhex(hx)
        s = b.decode("utf-8", errors="replace")
    except Exception as e:
        continue
    if "v1t{" in s:
        print("comb:", [shares[i][0] for i in comb])
        print("decoded:", s)

```


- Flag : `v1t{555_s3cr3t_sh4r1ng}`