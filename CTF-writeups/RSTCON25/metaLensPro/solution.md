# rce on exiftool

exiftool version is displayed when u upload a random jpg : 

```
 "ExifToolVersion": 12.23,
```


which has an rce - cve  exploit : https://ine.com/blog/exiftool-command-injection-cve-2021-22204-exploitation-and-prevention-strategies

- basically using `\c` to inject control characters.


thus i wrote a bash script to embed our payload and run the command cat flag.txt. we get the flag.

`MetaCTF{exif_to0l_versi0n_c4n_kill_you}`

