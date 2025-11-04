import bcrypt

# Read the hash
with open('hash.txt', 'r') as f:
    target_hash = f.read().strip()

print(f"Target hash: {target_hash}")
print("Starting to crack the hash...\n")

# Read the wordlist
with open('wordlist.txt', 'r', encoding='utf-8', errors='ignore') as f:
    wordlist = f.readlines()

print(f"Loaded {len(wordlist)} words from wordlist")

# Try each password
for i, password in enumerate(wordlist):
    password = password.strip()
    
    if i % 1000 == 0:
        print(f"Tried {i} passwords...")
    
    try:
        # Check if the password matches the hash
        if bcrypt.checkpw(password.encode('utf-8'), target_hash.encode('utf-8')):
            print(f"\n{'='*60}")
            print(f"PASSWORD FOUND!")
            print(f"{'='*60}")
            print(f"Password: {password}")
            print(f"{'='*60}")
            break
    except Exception as e:
        # Skip any passwords that cause errors
        continue
else:
    print("\nPassword not found in wordlist.")
