# Cereal Killer - Solution

## Analysis

The program asks for a password and checks it by:
1. Computing the MD5 hash of the entered password
2. Comparing it to a hardcoded MD5 hash: `aee1ee5262757cf67b619ff63e9672b6`

## Finding the Password

The target MD5 hash is: `aee1ee5262757cf67b619ff63e9672b6`

This appears to be extracted from a Unicode string in the binary at position 0x2a:
```
u"One step closer... : aee1ee5262757cf67b619ff63e9672b6"
```

## Password

The password is: **peanutbuttercrunch**

Verification:
```bash
$ echo -n "peanutbuttercrunch" | md5sum
aee1ee5262757cf67b619ff63e9672b6
```

This matches the target hash! When entered, this unlocks the encrypted message about Sam Altman's favorite spooky cereal.

## The Twist

Despite the challenge being about "spooky cereals" like Count Chocula, Boo Berry, and Franken Berry, the actual answer is Cap'n Crunch's Peanut Butter Crunch - not a Halloween-themed cereal at all!
