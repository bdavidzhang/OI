t = int(input())
for _ in range(t):
    a,b = map(int,input().split())
    m = max(a,b)
    n = min(a,b)
    if m >= 2*n:
        print(m*m)
    else: 
        print(n*n*4)
