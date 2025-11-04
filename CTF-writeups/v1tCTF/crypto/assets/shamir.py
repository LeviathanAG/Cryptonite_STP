# reconstruct_shamir_integer.py
from fractions import Fraction
from itertools import combinations

def lagrange_zero(points):
    # list of x,y 
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
