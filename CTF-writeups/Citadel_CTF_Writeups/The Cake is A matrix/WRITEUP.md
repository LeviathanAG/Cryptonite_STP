# The Cake is A Matrix -


**Flag:** `citadel{7h3_m4tr1x_i5_4_li3_4nd_50_wa5_1}`



## Initial Analysis

### Server.py 

Looking at `server.py`, we can see the encryption scheme:

```python
def weee(s):
    return [int(x) for x in ''.join([bin(ord(i))[2:].zfill(8) for i in s])]

key = gen_key()  # 64×64 matrix
enc = []
for i in range(0,len(flag),8):
    enc.append(multiply(key, weee(flag[i:i+8])))
```

- The flag is split into 8-character blocks
-  Each character is converted to 8 bits (via `weee()`)
- Each block becomes a 64-bit vector
-  Encryption: `ciphertext = K × plaintext (mod p)` where K is a 64×64 matrix
-  We get 56 oracle queries where we can submit 8 bytes and get back the encryption

### intuition needed to solve : 

`ASCII MSB is always 0`

ASCII characters have values 0-127, meaning msb is always 0. For each 8-byte block
- Bits at positions `0, 8, 16, 24, 32, 40, 48, 56 = 0`
- This reduces the unknown bits from 64 to 56 

and we have 56 queries so this is prolly intended.



### Initial Approach which failed

The natural approach would be to send inputs (vectors with only one bit set to 1):
- Send `[01000000, 00000000, 00000000, ...]` to learn column 1 of K
- Send `[00100000, 00000000, 00000000, ...]` to learn column 2 of K
so on


### ROADBLOCK

```python
# When we send binary with NULL bytes:
query = b'\x40\x00\x00\x00\x00\x00\x00\x00\n'
# The server only echoes: @^@^@^@^@^@^@^@ and closes
```

idk why this is happened tbh but i think it was due to ord. i needa reasearch more on this. GPT says its due to input() function. maybe true but i couldnt find anything concrete online. not like i did that much research.

##  Linear Algebra with Printable ASCII

but using printable chars was working with manual netcat so i just stuck to that.

### Generate Linearly Independent Queries

We need 56 queries using only printable ASCII charactersthat are linearly independent in the 56-dimensional space. random ascii characters was not decrypting properly 

```python
def generate_linearly_independent_queries():
    """Generate 56 queries that are linearly independent"""
    import random
    import numpy as np
    
    printable_chars = [chr(i) for i in range(48, 123)]  # '0' to 'z'
    queries = []
    query_bits = []
    
    while len(queries) < 56:
        # Generate random query
        query = ''.join(random.choices(printable_chars, k=8))
        bits = string_to_bits56(query)
        
        # Check for lin independence  after adding bits
        test_bits = query_bits + [bits]
        M = np.array(test_bits, dtype=int)
        
        if np.linalg.matrix_rank(M) == len(test_bits):
            queries.append(query)
            query_bits.append(bits)
    
    return queries
```
```
output : 
_1D@gbr6
O2@U1>`X
@\l0ldI;
wI67o]lf
XxLYn^p[
d3AE5A7D
_KK?Dv`]
<f<Lz_Yc
ojA2GD?v
qGaMtRCB
ZC[sM@zV
638_kO4L
zWxp0fcX
D`8PRwqC
U=tqF_];
iXjW0H1u
qnG4qw6T
5ii9SYCq
O?Xf?Gz`
PV9@I\A@
5_Asp5Ab
@9vZSjl>
7POSfby7
NIpB>QOD
BuQpY3zn
xuo<T@N4
LyCjROwz
Ye;Fx[Xh
4[Uo;x6=
\bA8rB\^
O[Wv?eAM
bFGh5Rzz
5?CurqK;
nd]za0mF
av:88YD]
e?_CTso6
OD0i_CgY
P05rsXn[
;9Gskps?
B7jrN^;u
pylr1gHu
lplDk8qp
@mRFkA1>
HpxD`MyX
v8x=xC8P
fG]VL[Ce
0uXegbK5
aHGoeFGN
NF9Ovbs^
FY0EP[aR
Q@Ssk<6V
_Imhb@>1
BSo5O_>d
UBa0hi7O
=wV3BoRl
bz\wr]eU

```

### Step 2: Collect Oracle Responses

Send all 56 queries and collect the encrypted responses:

```python
for query in queries:
    p.sendline(query.encode('ascii'))
    response = read_vector_response(p)
    responses.append(response)
```

Each response gives us: `K × query_bits[i] = response[i]`

### Mathematical Solution

Now we have a system of linear equations:
- `K × Q = R` where:
  - K is the 64×56 unknown key matrix. ive explained why 56 before only
  - Q is 56×56 matrix with query bit vectors as columns
  - R is 64×56 matrix with response vectors as columns

For each encrypted flag block:
- We need to solve: `K × flag_bits = enc_block`
- Since `K × Q = R`, we can write: `K = R × Q^(-1)` (using first 56 rows)

### The solving process:
1. Build matrix Q where `Q[row][col] = query_bits[col][row]`
2. Build matrix R where `R[row][col] = responses[col][row]`
3. For each encrypted block:
   - Solve: `R_square × x = enc_square` (using Gaussian elimination mod p)
   - Compute: `flag_bits = Q × x (mod p)`
   - Convert to binary: `flag_bits = flag_bits mod 2`
   - Convert 56 bits back to 8 ASCII characters

### cide 

```python
def solve_mod_gauss(A_rows, b, p):
    # Solve A*x = b (mod p) using Gauss elim
    n = len(A_rows)
    M = [row[:] + [bb % p] for row, bb in zip(deepcopy(A_rows), b)]
    
    for col in range(n):
        # Find pivot
        pivot_row = None
        for r in range(col, n):
            if M[r][col] % p != 0:
                pivot_row = r
                break
        
        if pivot_row is None:
            continue
        
        # Swap rows
        M[col], M[pivot_row] = M[pivot_row], M[col]
        
        # Scale pivot row
        inv = pow(M[col][col] % p, p-2, p)  # Fermat's little theorem
        for c in range(col, n+1):
            M[col][c] = (M[col][c] * inv) % p
        
        # Eliminate column
        for r in range(n):
            if r != col and M[r][col] % p != 0:
                factor = M[r][col] % p
                for c in range(col, n+1):
                    M[r][c] = (M[r][c] - factor * M[col][c]) % p
    
    return [M[i][n] % p for i in range(n)]
```

## all the scripts i ran also attached :

1. Generate linearly independent queries:** Run `generate_input.py` to create `input_queries.txt`
```python
#!/usr/bin/env python3
# Generate 56 linearly independent printable queries

import random
import numpy as np

def string_to_bits56(s):
    # Convert 8-char string to 56-bit vector 
    bits = []
    for c in s:
        val = ord(c)
        for bit_pos in range(6, -1, -1):
            bits.append((val >> bit_pos) & 1)
    return bits

# Use printable ASCII 48-122 ('0' to 'z')
printable_chars = [chr(i) for i in range(48, 123)]

print(f"gen liq ")
print(f"Using {len(printable_chars)} ")

# Generate random queries and keep only linearly independent ones
random.seed(42)  # For reproducibility
queries = []
query_bits = []

attempts = 0
max_attempts = 10000

while len(queries) < 56 and attempts < max_attempts:
    attempts += 1
    
    # Generate random query
    query = ''.join(random.choices(printable_chars, k=8))
    bits = string_to_bits56(query)
    
    # Check if adding this query maintains linear independence using numpy
    test_bits = query_bits + [bits]
    M = np.array(test_bits, dtype=int)
    
    if np.linalg.matrix_rank(M) == len(test_bits):
        # This query is linearly independent
        queries.append(query)
        query_bits.append(bits)
        
        if len(queries) % 10 == 0:
            print(f"Found {len(queries)}/56 LIQs")

if len(queries) == 56:
    print(f" generated 56 queries in {attempts} attempts")
    print(f"\nsaved  'input_queries.txt'")

    with open('input_queries.txt', 'w') as f:
        for i, q in enumerate(queries):
            f.write(f"{q}\n")
    
    
    
else:
    print(f" failed after {attempts} attemps")

```


### Input Queries.txt : 

```
_1D@gbr6
O2@U1>`X
@\l0ldI;
wI67o]lf
XxLYn^p[
d3AE5A7D
_KK?Dv`]
<f<Lz_Yc
ojA2GD?v
qGaMtRCB
ZC[sM@zV
638_kO4L
zWxp0fcX
D`8PRwqC
U=tqF_];
iXjW0H1u
qnG4qw6T
5ii9SYCq
O?Xf?Gz`
PV9@I\A@
5_Asp5Ab
@9vZSjl>
7POSfby7
NIpB>QOD
BuQpY3zn
xuo<T@N4
LyCjROwz
Ye;Fx[Xh
4[Uo;x6=
\bA8rB\^
O[Wv?eAM
bFGh5Rzz
5?CurqK;
nd]za0mF
av:88YD]
e?_CTso6
OD0i_CgY
P05rsXn[
;9Gskps?
B7jrN^;u
pylr1gHu
lplDk8qp
@mRFkA1>
HpxD`MyX
v8x=xC8P
fG]VL[Ce
0uXegbK5
aHGoeFGN
NF9Ovbs^
FY0EP[aR
Q@Ssk<6V
_Imhb@>1
BSo5O_>d
UBa0hi7O
=wV3BoRl
bz\wr]eU

```
1. **Run the exploit:** run  `solution_final.py`



```python
#!/usr/bin/env python3

from pwn import *
import re
from sympy import Matrix
import random

HOST = 'chall_citadel.cryptonitemit.in'
PORT = 54356

def generate_printable_queries():
    """
    Load pre-generated linearly independent queries from input_queries.txt
    These were generated to ensure full rank 
    """
    try:
        with open('input_queries.txt', 'r') as f:
            queries = [line.strip() for line in f if line.strip()]
        
        if len(queries) != 56:
            log.error(f"Expected 56 queries, got {len(queries)}")
            
            
            raise FileNotFoundError
        
        return queries
    except FileNotFoundError:
        log.error("input_queries.txt not found! Run generate_input.py again")
        exit(1)

def string_to_bits56(s):

    bits = []
    for c in s:
        val = ord(c)
        # Take bits 6-0 n skip bit 7 which is MSB
        for bit_pos in range(6, -1, -1):
            bits.append((val >> bit_pos) & 1)
    return bits

def bits56_to_string(bits):
    # Convert 56-bit vector back to 8-char string
    chars = []
    for i in range(8):
        val = 0
        for j in range(7):
            val = (val << 1) | bits[i*7 + j]
        chars.append(chr(val))
    return ''.join(chars)

def solve_mod_gauss(A_rows, b, p):
    """Solve A*x = b (mod p) using Gauss elim"""
    from copy import deepcopy
    n = len(A_rows)
    M = [row[:] + [bb % p] for row, bb in zip(deepcopy(A_rows), b)]
    
    for col in range(n):
        # Find pivot
        pivot_row = None
        for r in range(col, n):
            if M[r][col] % p != 0:
                pivot_row = r
                break
        
        if pivot_row is None:
            continue
        
        # Swap rows
        M[col], M[pivot_row] = M[pivot_row], M[col]
        
        # Scale pivot row
        inv = pow(M[col][col] % p, p-2, p)
        for c in range(col, n+1):
            M[col][c] = (M[col][c] * inv) % p
        
        # Eliminate column
        for r in range(n):
            if r != col and M[r][col] % p != 0:
                factor = M[r][col] % p
                for c in range(col, n+1):
                    M[r][c] = (M[r][c] - factor * M[col][c]) % p
    
    # Extract solution
    return [M[i][n] % p for i in range(n)]

def parse_vector(text):
    # Parse single list from text
    match = re.search(r'\[[\d\s,]+\]', text)
    if match:
        try:
            return eval(match.group(0))
        except:
            pass
    return None

def parse_list(text):
    """Parse nested list from text"""
    match = re.search(r'\[\[.*?\]\]', text, re.DOTALL)
    if match:
        try:
            return eval(match.group(0))
        except:
            pass
    return None

def main():
    context.log_level = 'info'
    
    log.info("Connecting")
    p = remote(HOST, PORT)
    
    # Read encrypted blocks
    log.info("Receiving 1st output")
    data = p.recvuntil(b'Now give me your ingredients:')
    text = data.decode('utf-8', errors='ignore')
    
    enc_blocks = parse_list(text)
    if not enc_blocks:
        log.error("Failed to parse encrypted blocks")
        return
    
    log.success(f"Got {len(enc_blocks)} encrypted blocks each with {len(enc_blocks[0])} elements")
    
    # Generate 56 printable queries
    queries = generate_printable_queries()
    log.info(f"Generated {len(queries)} printable queries")
   
    
    # Convert to bit vectors
    query_bits = [string_to_bits56(q) for q in queries]
    
    # Send queries and collect responses
    log.info("Sending queries")
    responses = []
    
    for i, query in enumerate(queries):
        # Wait for prompt
        p.recvuntil(b'Enter 8 bytes:')
        
        # Send as string (printable ASCII)
        p.sendline(query.encode('ascii'))
        
        # Read response
        try:
            resp_line = p.recvline()  # Echo
            cake_line = p.recvline()  # "have your cake:"

            # Read vector;  handle multi-line
            vec_text = ""
            depth = 0
            while True:
                line = p.recvline()
                line_str = line.decode('utf-8', errors='ignore')
                vec_text += line_str
                
                for ch in line_str:
                    if ch == '[':
                        depth += 1
                    elif ch == ']':
                        depth -= 1
                
                if depth == 0 and '[' in vec_text:
                    break
            
            vec = parse_vector(vec_text)
            if not vec:
                log.error(f"Failed to parse vector for query {i+1}")
                log.info(f"Vec text: {vec_text[:200]}")
                return
            
            responses.append(vec)
            
            if (i+1) % 10 == 0:
                log.info(f"Progress: {i+1}/56")
        
        except Exception as e:
            log.error(f"Error on query {i+1}: {e}")
            return
    
    log.success("Collected all ")
    
    # Get prime
    p.sendline(b'dummy')
    final = p.recvall(timeout=2)
    final_text = final.decode('utf-8', errors='ignore')
    
    match = re.search(r'prime is\s+(\d+)', final_text)
    if not match:
        log.error("Failed to parse prime")
        return
    
    prime = int(match.group(1))
    log.success(f"Prime p = {prime}")
    
    # Now solve using the same approach as solution1.py
    # We have: K * query_bits[i] = responses[i] for all i
    # Transpose query_bits to get Q where Q[row][col] = query_bits[col][row]
    Q = [[query_bits[col][row] for col in range(56)] for row in range(56)]
    
    log.info("Solving. if we reach here we have parsed all data correctly")
    flag_blocks = []
    
    for block_idx, enc_block in enumerate(enc_blocks):
        # Build R: 64 rows, 56 columns (response vectors as columns)
        R = [[responses[col][row] % prime for col in range(56)] for row in range(64)]
        
        enc_mod = [x % prime for x in enc_block]
        
        # Use first 56 rows of R to make it square
        R_square = R[:56]
        enc_square = enc_mod[:56]
        
        # Solve R_square * x = enc_square (mod prime) using G.E
        x = solve_mod_gauss(R_square, enc_square, prime)
        
        # Compute flag_bits = Q * x (mod prime)
        flag_bits = []
        for row in range(56):
            val = sum(Q[row][col] * x[col] for col in range(56)) % prime
            flag_bits.append(val)
        
        # Convert to binary
        if not all(b in [0, 1] for b in flag_bits):
            log.info(f"Block {block_idx} Converting to binary with mod 2")
            flag_bits = [b % 2 for b in flag_bits]
        
        flag_str = bits56_to_string(flag_bits)
        log.info(f"Block {block_idx}: {flag_str!r}")
        flag_blocks.append(flag_str)
    
    # Construct flag
    flag_inner = ''.join(flag_blocks)
    flag = f"citadel{{{flag_inner}}}"
    
    
    print(f"FLAG: {flag}")
   
    
    p.close()

if __name__ == '__main__':
    main()


```

OUTPUT : 

```

C:\Citadel_CTF_Writeups\The Cake is A matrix>python solution_final.py
[*] Connecting
[x] Opening connection to chall_citadel.cryptonitemit.in on port 54356
[x] Opening connection to chall_citadel.cryptonitemit.in on port 54356: Trying 74.225.246.247
[+] Opening connection to chall_citadel.cryptonitemit.in on port 54356: Done
[*] Receiving 1st output
[+] Got 4 encrypted blocks each with 64 elements
[*] Generated 56 printable queries
[*] Sending queries
[*] Progress: 10/56
[*] Progress: 20/56
[*] Progress: 30/56
[*] Progress: 40/56
[*] Progress: 50/56
[+] Collected all 
[x] Receiving all data
[x] Receiving all data: 94B
[+] Receiving all data: Done (94B)
[*] Closed connection to chall_citadel.cryptonitemit.in port 54356
[+] Prime p = 270926864520661229437198016196284053621
[*] Solving. if we reach here we have parsed all data correctly
[*] Block 0: '7h3_m4tr'
[*] Block 1: '1x_i5_4_'
[*] Block 2: 'li3_4nd_'
[*] Block 3: '50_wa5_1'
FLAG: citadel{7h3_m4tr1x_i5_4_li3_4nd_50_wa5_1}

```

## Flag

```
citadel{7h3_m4tr1x_i5_4_li3_4nd_50_wa5_1}
```


## Files

- `solution_final.py` -  exploit using linear indep* queries
- `generate_input.py` - Script to generate linearly independent queries
- `input_queries.txt` - Pre-generated 56 linearly independent queries
- `server.py` - Challenge server code (reference)


## Tools Used

- Python 3
- pwntools (for network communication)
- numpy (for linear algebra)

- Custom Gaussian elimination implementation

