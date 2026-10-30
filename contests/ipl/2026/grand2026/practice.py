t = int(input())

for _ in range(t):
    n = int(input())
    a = list(map(int,input().split()))
    maxi = 0
    for i in range(n):
        for j in range(i+1,n):
            maxi = max(a[i]^a[j],maxi)
    print(maxi)