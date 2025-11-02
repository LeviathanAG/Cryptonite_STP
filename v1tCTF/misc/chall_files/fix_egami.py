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

