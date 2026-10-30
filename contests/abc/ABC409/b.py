n = int(input())
a = sorted(list(map(int,input().split())))
ans = 0
for i in range(1,n+1):
    if a[n-i] > ans:
        ans += 1
print(ans)
