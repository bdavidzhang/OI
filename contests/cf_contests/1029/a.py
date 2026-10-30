from math import log2,ceil
t = int(input())

for _ in range(t):
    x = int(input())
    n = ceil(log2(x+1))
    if x == 0:
        print(0)
    else:
        print(2*n+1)
        
