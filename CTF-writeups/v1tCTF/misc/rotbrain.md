# Rotbrain

we ae given gnp.egami which is image.png in reverse and if we do `XXD` on it we can see the png headers in reverse but only this doesnt work since xxd was giving us utf-8 which i converted to latin which preserves the bytes.

script : 
```
#!/usr/bin/env python3
import sys

if len(sys.argv) != 3:
    print(f"Usage: {sys.argv[0]} input_file output_file")
    sys.exit(1)

inp, outp = sys.argv[1], sys.argv[2]

with open(inp, "rb") as f:
    data = f.read()


decoded = data.decode("utf-8").encode("latin1")


reversed_bytes = decoded[::-1]

with open(outp, "wb") as f:
    f.write(reversed_bytes)


```