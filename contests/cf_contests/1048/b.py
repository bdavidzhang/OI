t = int(input())

for _ in range(t):
    n,m = map(int, input().split())
    a = list(map(int, input().split()))

    b = sorted(a)
    ans = 0
    k = min(n,m)
    
    for i in range(k):
        rate = b[n-1-i]
        times = m-i
        ans += rate * times
    print(ans)
