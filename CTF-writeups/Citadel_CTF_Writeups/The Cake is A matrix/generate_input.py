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
