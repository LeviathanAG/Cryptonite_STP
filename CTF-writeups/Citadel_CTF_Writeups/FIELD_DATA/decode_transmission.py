ENCODE_TABLE = {
    '@': '000000000110',  # 7-8
    '#': '100000000110',  # 12-7-8
    '\n': '010000000110',  # 11-7-8 (Carriage Return)
    ' ': '000000000000',  # (Space)
    'A': '100100000000',  # 12-1
    'B': '100010000000',  # 12-2
    'C': '100001000000',  # 12-3
    'D': '100000100000',  # 12-4
    'E': '100000010000',  # 12-5
    'F': '100000001000',  # 12-6
    'G': '100000000100',  # 12-7
    'H': '100000000010',  # 12-8
    'I': '100000000001',  # 12-9
    'J': '010100000000',  # 11-1
    'K': '010010000000',  # 11-2
    'L': '010001000000',  # 11-3
    'M': '010000100000',  # 11-4
    'N': '010000010000',  # 11-5
    'O': '010000001000',  # 11-6
    'P': '010000000100',  # 11-7
    'Q': '010000000010',  # 11-8
    'R': '010000000001',  # 11-9
    'S': '001010000000',  # 0-2
    'T': '001001000000',  # 0-3
    'U': '001000100000',  # 0-4
    'V': '001000010000',  # 0-5
    'W': '001000001000',  # 0-6
    'X': '001000000100',  # 0-7
    'Y': '001000000010',  # 0-8
    'Z': '001000000001',  # 0-9
    ')': '100000100010',  # 12-4-8
    '-': '010000000000',  # 11
    '+': '100000000000',  # 12
    '<': '100000001010',  # 12-6-8
    '=': '000001000010',  # 3-8
    '>': '000000001010',  # 6-8
    '&': '000010000010',  # 2-8
    '$': '010001000010',  # 11-3-8
    '*': '010000100010',  # 11-4-8
    '(': '001000100010',  # 0-4-8
    '%': '001000010010',  # 0-5-8
    ':': '000000010010',  # 5-8
    '?': '101000000000',  # 12-0
    '!': '011000000000',  # 11-0
    ',': '001001000010',  # 0-3-8
    '\\': '001000001010', # 0-6-8 (End of Message)
    '0': '001000000000',  # 0
    '1': '000100000000',  # 1
    '2': '000010000000',  # 2
    '3': '000001000000',  # 3
    '4': '000000100000',  # 4
    '5': '000000010000',  # 5
    '6': '000000001000',  # 6
    '7': '000000000100',  # 7
    '8': '000000000010',  # 8
    '9': '000000000001',  # 9
    "'": '000000100010', # 4-8
    ';': '010000001010',  # 11-6-8
    '/': '001100000000',  # 0-1
    '.': '100001000010',  # 12-3-8
    '[': '010000010010',  # 11-5-8 (LC: Lower Case)
    ']': '100000010010',  # 12-5-8 (UC: Upper Case)
    '{': '000010000010',  # 2-8
    '}': '100010000010',  # 12-2-8
}

# Create reverse mapping (bits -> character)
DECODE_TABLE = {v: k for k, v in ENCODE_TABLE.items()}

# Read the transmission file
import os
script_dir = os.path.dirname(os.path.abspath(__file__))
transmission_path = os.path.join(script_dir, 'transmission.txt')

with open(transmission_path, 'r') as f:
    transmission = f.read().strip()

# Split into 12-bit chunks and decode
decoded_message = []
for i in range(0, len(transmission), 12):
    chunk = transmission[i:i+12]
    if len(chunk) == 12:  # Make sure we have a complete 12-bit chunk
        if chunk in DECODE_TABLE:
            decoded_message.append(DECODE_TABLE[chunk])
        else:
            decoded_message.append(f'[UNKNOWN: {chunk}]')

# Print the decoded message
result = ''.join(decoded_message)
print("Decoded message:")
print(result)
print("\n" + "="*50)
print(f"Total bits: {len(transmission)}")
print(f"Total chunks (12-bit): {len(transmission) // 12}")
print(f"Decoded characters: {len(decoded_message)}")
