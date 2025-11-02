# duckRPG

- we are given a game.bat which is very simple and easy to understand.
- we are also given result.bat which is obfuscated.

- chall description says we need to reach the secret ending.
- if i tried patching the game it keeps erroring out.
- i saw that the input to the result.bat was frag123 + hash.
- i calcualted the correct frag sequence to be `unlocktheduck`
- we can get the hash of the game without any modifications using this : 
```
PS C:\Users\norma\Downloads\duck_rpg> certutil -hashfile .\game.bat SHA256
SHA256 hash of .\game.bat:
8392dcc7b6fdebd5a70211c1e21497a553b31f2c70408b772c4a313615df7b60
CertUtil: -hashfile command completed successfully.
PS C:\Users\norma\Downloads\duck_rpg>
```

- now we can directly pass the new frag and hash which gives us the flag.

```
cmd /c "result.bat unlocktheduck 8392dcc7b6fdebd5a70211c1e21497a553b31f2c70408b772c4a313615df7b60"
v1t{p4tch_th3_b4tch_t0_g3t_th3_s3cr3t_3nd1ng}
```

- `v1t{p4tch_th3_b4tch_t0_g3t_th3_s3cr3t_3nd1ng}`