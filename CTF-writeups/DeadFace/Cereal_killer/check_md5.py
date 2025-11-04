import hashlib
import itertools

target_hash = "aee1ee5262757cf67b619ff63e9672b6"

# Try flag format and other variations
test_strings = [
    # Original cereals
    "Count Chocula",
    "Franken Berry", 
    "Boo Berry",
    "Fruit Brute",
    "Fruity Yummy Mummy",
    # Flag format
    "flag{Count Chocula}",
    "flag{Boo Berry}",
    "flag{Franken Berry}",
    "FLAG{Count Chocula}",
    # Try with trademark symbol
    "Count Chocula®",
    "Boo Berry®",
    # Try different cases for "Sam Altman"
    "Sam Altman",
    "sam altman",
    "SamAltman",
    # Try cereal + Sam Altman
    "Count Chocula Sam Altman",
    # Common CTF answers
    "BOOBERRY",
    "COUNTCHOCULA", 
    # Try o1 model references (since Sam Altman/OpenAI)
    "o1",
    "o1-preview",
    "gpt-4",
    "ChatGPT",
    "OpenAI",
    # Try the actual string from decompilation
    "One step closer...",
    # Spooky references
    "Halloween",
    "halloween",
    "spooky",
    "Spooky",
    # Try combinations
    "BooBerrySamAltman",
    "CountChoculaSamAltman",
]

print(f"Target MD5: {target_hash}")
print(f"\nNote: MD5 hash typically comes from an online rainbow table or")
print(f"needs to be brute-forced. Let me try common variations...\n")
print("-" * 70)

found = False
for test_str in test_strings:
    md5_hash = hashlib.md5(test_str.encode()).hexdigest()
    match = "✓✓✓ MATCH! ✓✓✓" if md5_hash == target_hash else ""
    if match:
        found = True
        print(f"*** {test_str:40} -> {md5_hash} {match}")
    else:
        print(f"    {test_str:40} -> {md5_hash}")

if not found:
    print("\n" + "="*70)
    print("No match found. The password may need to be looked up in an")
    print("MD5 rainbow table database or brute-forced.")
    print("="*70)
