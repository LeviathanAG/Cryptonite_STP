enc = [16, 49, 14, 21, 7, 48, 49, 15, 6, 48, 44, 10, 12, 49, 20, 0, 23]

for key in range(1, 101):
    possibles = []
    for val in enc:
        chars = []
        for c in range(32, 127):
            if c % key == val:
                chars.append(chr(c))
        if not chars:
            break
        possibles.append(chars)
    
    if len(possibles) == len(enc):
        def generate(index, current):
            if index == len(possibles):
                if current.startswith('v1t{') and current.endswith('}'):
                    print(f"Key: {key}")
                    print(f"Flag: {current}")
                return
            for ch in possibles[index]:
                generate(index + 1, current + ch)
        
        generate(0, '')
