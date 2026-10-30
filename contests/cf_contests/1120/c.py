t = int(input())
for _ in range(t):
    n = int(input())
    a = list(map(int,input().split()))
    diff = [0] * (n+1)
    for k in range(n):
        k0 = k + 1
        l = a[k] * k0
        r = min(n - 1, (a[k] + 1) * k0 - 1)
        if l <= r:
            diff[l] += 1
            diff[r + 1] -= 1
    
    b = 0
    ans = []
    for i in range(n):
        b += diff[i]
        if b == 0:
            ans.append(i)
    print(len(ans))
    print(" ".join(map(str, ans)))
        