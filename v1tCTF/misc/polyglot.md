# polyglot


we can rename the file extensions to pdf and mp4.


- mp4 gives us a password and pdf gives us hints about steghide

- steghide doesnt work for jpg files
- when u run binwalk :
```bash
(base) ss@Satwik:/mnt/c/ctf_writeups/v1tCTF/misc$ binwalk polyglot.png

DECIMAL       HEXADECIMAL     DESCRIPTION
--------------------------------------------------------------------------------
53            0x35            PDF document, version: "1.7"
25692         0x645C          HTML document header
25952         0x6560          HTML document footer
25971         0x6573          PNG image, 1024 x 1024, 8-bit/color RGBA, non-interlaced
26012         0x659C          Zlib compressed data, best compression
2225039       0x21F38F        PDF document, version: "1.7"
2225627       0x21F5DB        Zlib compressed data, default compression
2231147       0x220B6B        Zlib compressed data, default compression
2232775       0x2211C7        Zlib compressed data, default compression
2233299       0x2213D3        Zlib compressed data, default compression
2233644       0x22152C        Zlib compressed data, default compression
6078442       0x5CBFEA        Zlib compressed data, default compression
6078833       0x5CC171        Zlib compressed data, default compression
6103898       0x5D235A        Zlib compressed data, default compression
6104351       0x5D251F        Zlib compressed data, default compression
6156810       0x5DF20A        Zlib compressed data, default compression
6158648       0x5DF938        Zip archive data, at least v2.0 to extract, compressed size: 142094, uncompressed size: 160694, name: angri.jpg
6300888       0x6024D8        End of Zip archive, footer length: 22
extract these files
```

we find angri.jpg

- we can run this cmd to extract the image manually


```bash
(base) ss@Satwik:/mnt/c/ctf_writeups/v1tCTF/misc/clean_extract$ dd if=polyglot.png bs=1 skip=$((0x5DF938)) of=recovered.zip
142262+0 records in
142262+0 records out
142262 bytes (142 kB, 139 KiB) copied, 40.4421 s, 3.5 kB/s
(base) ss@Satwik:/mnt/c/ctf_writeups/v1tCTF/misc/clean_extract$ file recovered.zip
recovered.zip: Zip archive data, at least v2.0 to extract, compression method=deflate
(base) ss@Satwik:/mnt/c/ctf_writeups/v1tCTF/misc/clean_extract$
```

- when u unzip the file u et a jp which we can use steghide on with our password

flag : `v1t{duck_l0v3_w4tch1ng_p2r3}`