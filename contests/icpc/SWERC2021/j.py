from math import gcd
import math


def count_divisors_efficient(n,m):
    count = 0
    # Iterate from 1 to the square root of n
    for i in range(1, int(math.sqrt(n)) + 1):
        if n % i == 0:
            # If the divisors are the same (perfect square), count only one
            if n / i == i:
                m[i] = 1
                count += 1
            else:
                # Otherwise, count both divisors in the pair
                m[i] = 1
                m[n // i] = 1
                count += 2
    return count


t = int(input())
for _ in range(t):
    l,w = map(int, input().split())
    m = {}
    g1 = gcd(l,w-2)
    g2 = gcd(l-2,w)
    g3 = gcd(l-1,w-1)
    count_divisors_efficient(g1,m)
    count_divisors_efficient(g2,m)
    count_divisors_efficient(g3,m)
    if ((l-1) % 2 == 0 and w % 2 == 0) or (l % 2 == 0 and (w-1) % 2 == 0):
        m[2] = 1
    result = sorted(m.keys())
    print(" ".join(map(str, [len(result)] + result)))
    