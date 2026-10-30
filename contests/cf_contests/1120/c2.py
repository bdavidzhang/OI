MOD = 10**9 + 7


def solve(n, a):
    need = [-1] * n
    diff = [0] * (n + 1)

    for k0, k_val in enumerate(a, start=1):
        l = k_val * k0
        r  = min(
            n - 1, (k_val + 1) * k0 - 1
        )
        if l <= r:
            diff[l] += 1
            diff[r + 1] -= 1

        for q in range(k_val):
            ri = min(n - 1, (q + 1) * k0 - 1)
            le= q* k0
            need[ri] = max(need[ri], le)

    no = [False] * n
    act = 0
    for pos in range(n):
        act += diff[pos]
        no[pos] = act > 0

    dp = [0] * n
    ans = 1
    low = -1

    for pos in range(n):
        tar = max(low, need[pos])
        cur = ans
        while low < tar:
            if low == -1:
                ans -= 1
            else:
                ans -= dp[low]
            ans %= MOD
            low += 1
        low = tar

        if not no[pos]:
            dp[pos] = cur
            ans = (ans + dp[pos]) % MOD

    return ans


t = int(input())
for _ in range(t):
    n = int(input())
    a = list(map(int, input().split()))
    print(solve(n, a))
    
