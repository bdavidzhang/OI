n = int(input())

MOD = int(1e9+7)

ways = [1,1,2,4,8,16,32]
for k in range(7,n+1):
    ans = 0
    for j in range(1,7):
        ans += (ways[k-j] % MOD)
    ways.append(ans % MOD)

print(int(ways[n] % MOD))


