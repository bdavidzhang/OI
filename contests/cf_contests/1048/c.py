import sys
input = sys.stdin.readline

t = int(input())

for _ in range(t):
    k, x = map(int, input().split())
    
    if x == 2**k:
        print(0)
        print()
        continue

    reverse = False
    if x < 2**k:
        reverse = True
        x = 2**(k + 1) - x

    p = (x & -x).bit_length() - 1
    
    n = k - p

    S = (x >> p) - 1
    S >>= 1
    
    ops = []
    temp_S = S
    for _ in range(n):
        bit = temp_S & 1 
        ops.append(bit + 1) 
        temp_S >>= 1      

    if reverse:
        for i in range(n):
            ops[i] = 1 if ops[i] == 2 else 2
    
    print(n)
    print(*ops)