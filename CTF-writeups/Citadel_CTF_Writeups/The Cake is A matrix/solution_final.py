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
