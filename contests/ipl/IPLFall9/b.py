t = int(input())
for _ in range(t):
    n = int(input())
    x = input().split()
    a = [int(c) for c in x]
    a.sort()
    d = 1e18 
    for i in range(n-1):
        dif = a[i+1]-a[i]
        if(d > dif): 
            d = dif 
    print(d)