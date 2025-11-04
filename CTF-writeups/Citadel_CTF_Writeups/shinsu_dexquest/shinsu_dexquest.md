# Shinsu DEXquest

300

As you climb the path, a guardian emerges, its form shifting between the visage of a long-dead climber and a metallic sentinel.

It moves with a strange grace, holding out a cartridge containing a single file.

You realize the file is compatible with the device you carry and may be the key to continue your ascent toward the Citadel’s heart.

## Solution

First, I used JADX to decompile the APK file, as that was given in the server resources.

I looked at the decompiled directory and found the main application package at `com.shinsu.dexquest` and saw these two files:

- `com/shinsu/dexquest/screens/Vault.java` - Contains password validation logic
- `com/shinsu/dexquest/screens/NextRoom.java` - Contains flag decryption logic

The `Vault.java` file contained a `checkPassword()` function that validates a 99-digit password by checking each individual position:

```java
public final boolean checkPassword(String password) {
    if (password.length() != 99) {
        return false;
    }
    if (password.charAt(0) != '2') return false;
    if (password.charAt(1) != '4') return false;
    if (password.charAt(2) != '6') return false;
    ...
}
```

By extracting all 99 character checks, I reconstructed the password:

`246451121036528202623890120011222498714684815355211850969748918921930947358058258074789422723982625`

The `NextRoom.java` file contained the XOR decryption logic for the flag:

```java
public final String getFlag() {
    String password = getPassword();
    String ciphertext = "VkZVWkVMWHtaYT...";
    byte[] decode = Base64.getDecoder().decode(ciphertext);
    byte[] bytes = password.getBytes(Charsets.UTF_8);

    for (int i = 0; i < decode.length; i++) {
        decode[i] = (byte) (decode[i] ^ bytes[i % bytes.length]);
    }

    return new String(decode, Charsets.UTF_8);
}
```

Using the password found in Step 3, I wrote a Python script to decrypt the flag:

```python
import base64

password = "246451121036528202623890120011222498714684815355211850969748918921930947358058258074789422723982625"
ciphertext = "VkZVWkVMWHtaYTNzYmt3dlozQjladj1pWGJ5...=="

decoded = base64.b64decode(ciphertext)
password_bytes = password.encode('utf-8')
flag = bytearray()

for i in range(len(decoded)):
    flag.append(decoded[i] ^ password_bytes[i % len(password_bytes)])

print(flag.decode('utf-8'))
```

Running this yielded the flag.


## Flag

**citadel{f33ls_g00d_to_n0t_g3t_d33p_fr13d}**