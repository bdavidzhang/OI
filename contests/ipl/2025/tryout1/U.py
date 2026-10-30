#!/usr/bin/env python3
# precompute_construct_integer.py
# Usage:
#   python precompute_construct_integer.py        # defaults max_n=81, max_len=7
#   python precompute_construct_integer.py 200 8  # max_n=200, max_len=8
#
# Warning: increasing max_len grows runtime combinatorially.

import sys
from itertools import combinations_with_replacement, permutations
from math import gcd
from collections import defaultdict
import csv
import time

def all_permutation_values(digits):
    """Return set of integers obtainable by permuting `digits` and stripping leading zeros via int()."""
    vals = set()
    # use set(permutations(...)) to avoid duplicate permutations with repeated digits
    for p in set(permutations(digits)):
        s = ''.join(p)
        vals.add(int(s))
    return vals

def minimal_nonleading_value(digits):
    """Return minimal integer among permutations that do not start with '0'."""
    vals = set()
    for p in set(permutations(digits)):
        if p[0] == '0':
            continue
        vals.add(int(''.join(p)))
    if not vals:
        return None
    return min(vals)

def enumerate_multisets_of_digits_of_length(L):
    """Yield digit-lists (as strings) for every multiset of length L using combinations_with_replacement."""
    digits = '0123456789'
    for comb in combinations_with_replacement(digits, L):
        # comb is non-decreasing tuple of digits, e.g. ('0','0','1','3')
        yield list(comb)

def precompute(max_n=81, max_len=7, verbose=True):
    """Precompute minimal z mapping gcd -> minimal z among all digit-multisets length 1..max_len.
       Return dict mapping n -> minimal z (for n <= max_n)."""
    start = time.time()
    g_to_minz = dict()
    checked = 0
    for L in range(1, max_len + 1):
        if verbose:
            print(f"[L={L}] enumerating multisets...")
        for digits in enumerate_multisets_of_digits_of_length(L):
            # skip multisets that have no permutation without leading zero (e.g., all zeros)
            minz = minimal_nonleading_value(digits)
            if minz is None:
                continue
            vals = all_permutation_values(digits)
            g = 0
            for v in vals:
                g = gcd(g, v)
                if g == 1:
                    # can't get lower than 1; continue computing, but early break isn't helpful because we still need gcd 1
                    pass
            # store minimal z for this gcd
            if g in g_to_minz:
                if minz < g_to_minz[g]:
                    g_to_minz[g] = minz
            else:
                g_to_minz[g] = minz
            checked += 1

    end = time.time()
    if verbose:
        print(f"Enumerated {checked} multisets up to length {max_len} in {end - start:.2f}s. Found {len(g_to_minz)} gcd values.")
    # Build result mapping for 1..max_n
    res = {}
    for n in range(1, max_n + 1):
        res[n] = g_to_minz.get(n, -1)
    return res, g_to_minz

def save_csv(mapping, filename="precompute_results.csv"):
    with open(filename, "w", newline="") as f:
        w = csv.writer(f)
        w.writerow(["n", "min_z_or_-1"])
        for n in sorted(mapping):
            w.writerow([n, mapping[n]])
    print(f"Saved results to {filename}")

def main():
    max_n = 81
    max_len = 8
    if len(sys.argv) >= 2:
        try:
            max_n = int(sys.argv[1])
        except:
            pass
    if len(sys.argv) >= 3:
        try:
            max_len = int(sys.argv[2])
        except:
            pass

    print(f"Precomputing minimal z for n=1..{max_n} using digit-multisets up to length {max_len}...")
    mapping, full_gmap = precompute(max_n=max_n, max_len=max_len, verbose=True)

    # print results
    for n in range(1, max_n + 1):
        print(f"{n}: {mapping[n]}")

    # also save CSV
    save_csv(mapping, filename=f"precompute_n_1_to_{max_n}_len_{max_len}.csv")

if __name__ == "__main__":
    main()
