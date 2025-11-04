# Specimen 512

- we are given a .fasta file which is used in DNA encoding but in the headers we are given these details

```
>DNA_ARCHIVE_sample|size_target_mb=5
; hint: encoding=base64->triplet-codon (lexicographic AAA..TTT => b64 idx 0..63)
; pad_count=2  ; note: base64 padding removed from stream
; gc_hint: some decoy regions have varying GC to confuse simple heuristics
```

- if u ignore the decoy sequences and focus on archive_core and understand the headers : 
we learn that it is  not biological data at all, the DNA bases are being used as a 4 symbol alphabet to encode base64 via 3-letter chunks AND THEN WE ADD == PADDING to and store it in a .bin file.

- when i was going throught the hex dump i came across this : 
```
00002710: 504b 0304 1400 0000 0800 0979 4d5b 8251  PK.........yM[.Q
00002720: 749a 2800 0000 2600 0000 0800 0000 666c  t.(...&.......fl
00002730: 6167 2e74 7874 2b33 2ca9 3636 b030 3737  ag.txt+3,.66.077
00002740: 3136 4a31 3430 3233 3730 4b31 4fb5 3030  16J1402370K1O.00
00002750: 4d49 b430 314b 3436 4a36 aee5 0200 504b  MI.01K46J6....PK
00002760: 0304 1400 0000 0800 0979 4d5b 686c a1ef  .........yM[hl..
00002770: 3000 0000 3200 0000 0a00 0000 7265 6164  0...2.......read
00002780: 6d65 2e74 7874 0bc9 c82c 5600 a244 0517  me.txt...,V..D..
00002790: 3f47 05c7 a2e4 8ccc b254 8582 c4ca 9cfc  ?G.......T......
000027a0: c414 3d05 9fcc b454 85b4 ccbc 1490 8ab4  ..=....T........
000027b0: 9cc4 743d 2e00 504b 0102 1403 1400 0000  ..t=..PK........
000027c0: 0800 0979 4d5b 8251 749a 2800 0000 2600  ...yM[.Qt.(...&.
000027d0: 0000 0800 0000 0000 0000 0000 0000 a481  ................
000027e0: 0000 0000 666c 6167 2e74 7874 504b 0102  ....flag.txtPK..
000027f0: 1403 1400 0000 0800 0979 4d5b 686c a1ef  .........yM[hl..
00002800: 3000 0000 3200 0000 0a00 0000 0000 0000  0...2...........
00002810: 0000 0000 8001 4e00 0000 7265 6164 6d65  ......N...readme
00002820: 2e74 7874 504b 0506 0000 0000 0200 0200  .txtPK..........
00002830: 6e00 0000 a600 0000 0000 0cc1 2eec 398e  n.............9.
```

- with binwalk i was able to extract the flag.txt which gave me the flag : `v1t{30877432d1026706d7e805da846a32c3}`
