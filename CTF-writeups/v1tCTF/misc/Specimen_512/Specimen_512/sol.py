from base64 import b64decode
from itertools import product

# Build AAA..TTT → base64 char map
bases = 'ACGT'
codons = [''.join(p) for p in product(bases, repeat=3)]
b64alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/"
codon_to_b64 = {codon: b64alphabet[i] for i, codon in enumerate(codons)}

dna = ''
use = False

with open('Specimen_512.fasta') as f:
    for line in f:
        line = line.strip()
        if line.startswith('>'):
            use = line.startswith('>archive_core')
            continue
        if line.startswith(';') or not use:
            continue
        dna += line

# Trim leftover bases so length % 3 == 0
dna = dna[:len(dna) // 3 * 3]

# Convert triplets to base64
b64 = ''.join(codon_to_b64[dna[i:i+3]] for i in range(0, len(dna), 3))

# Add b64 padding (= padding stripped earlier)
b64 += '=='

data = b64decode(b64)
open('output.bin', 'wb').write(data)

print("Wrote output.bin, run: file output.bin")
