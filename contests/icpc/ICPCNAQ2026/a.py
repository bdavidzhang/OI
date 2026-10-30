MOD = 998244353


n = int(input())

ans = (n % MOD) * ((n+1) % MOD) * ((n+2) % MOD) % MOD
ans = ans * (pow(6,-1,MOD) % MOD) % MOD
print(ans)
