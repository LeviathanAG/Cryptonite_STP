binwalk to get the flag

```
ss@Satwik:/mnt/c/Citadel_CTF_Writeups/Omniscient_metadata$ binwalk -e challenge.jpg

DECIMAL       HEXADECIMAL     DESCRIPTION
--------------------------------------------------------------------------------
87530         0x155EA         PNG image, 640 x 613, 8-bit/color RGB, non-interlaced
87709         0x1569D         Zlib compressed data, best compression
```


flag : ![alt text](extracted_1759777174171.png)