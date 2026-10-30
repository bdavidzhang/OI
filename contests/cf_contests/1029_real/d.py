from math import gcd 

t = int(input())

for _ in range(t):
    n = int(input())
    arr = list(map(int,input().split()))
    good = 1
    for i in range(n):
        d = gcd(i+1,n-i)
        if arr[i] % d == 0:
            pass
        else:
            good = 0
            break
    if good:
        print("YES")
    else:
        print("NO")
     