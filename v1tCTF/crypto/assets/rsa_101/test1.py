# save as brute_mod.py and run: python brute_mod.py
import itertools, string, multiprocessing as mp
from functools import partial

n = 31698460634924412577399959706905435239651
e = 65537
c = 23648999580642514140599125257944114844209

prefix = "v1t{"   # use exact known prefix
suffix_end = "}"   # known closing char
alphabet = string.ascii_lowercase + string.digits  # tune as needed
min_L, max_L = 1, 5  # try inner lengths 1..5 (adjust)

A = int.from_bytes(prefix.encode(), 'big')
# we'll construct candidates as: candidate = prefix + inner + suffix_end
def test_chunk(start_tuple):
    inner_tuple, = start_tuple  # single tuple wrapper
    inner = ''.join(inner_tuple)
    cand = prefix + inner + suffix_end
    m = int.from_bytes(cand.encode(), 'big')
    if pow(m, e, n) == c:
        return cand
    return None

def worker_for_length(L):
    # generate all inner tuples of length L in lexicographic order
    gen = itertools.product(alphabet, repeat=L)
    # use chunks to reduce IPC overhead
    CHUNK = 1000
    chunk = []
    for idx, tup in enumerate(gen, 1):
        chunk.append((tup,))
        if len(chunk) >= CHUNK:
            # parallel map this chunk
            with mp.Pool() as pool:
                for res in pool.imap_unordered(test_chunk, chunk):
                    if res:
                        return res
            chunk = []
    # final partial chunk
    if chunk:
        with mp.Pool() as pool:
            for res in pool.imap_unordered(test_chunk, chunk):
                if res:
                    return res
    return None

if __name__ == "__main__":
    for L in range(min_L, max_L+1):
        print("Trying length", L)
        found = worker_for_length(L)
        if found:
            print("FOUND:", found)
            break
    else:
        print("Not found up to length", max_L)
