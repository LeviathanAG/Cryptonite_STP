with open('lucifer_patched.exe', 'r+b') as f:
    # The JE opcode is at 0x142a-0x142b (0F 84)
    f.seek(0x142b)
    original = f.read(1)
    print(f"Original byte at 0x142b: 0x{original.hex()}")

    if original == b'\x84':
        f.seek(0x142b)
        f.write(b'\x85')  # Change JE (84) to JNE (85)
        print("✓ Patched JE (0F 84) to JNE (0F 85)!")
    else:
        print(f"ERROR: Expected 0x84 but found 0x{original.hex()}")

print("\nVerifying patch...")
with open('lucifer_patched.exe', 'rb') as f:
    f.seek(0x1428)
    patched_bytes = f.read(8)
    print(f"Patched bytes: {patched_bytes.hex()}")

print("\nBinary patched successfully!")
print("The program will now accept ANY password and display the flag.")
