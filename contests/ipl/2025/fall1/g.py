t = int(input())

MOD = int(1e9+7)
for _ in range(t):
    l, r, k = map(int, input().split())
    #built in binexp function
    print((pow(9 // k + 1, r, MOD) - pow(9 // k + 1, l, MOD) + MOD) % MOD)