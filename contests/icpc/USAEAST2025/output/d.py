c = int(input())
v = sorted(map(int, input().split()))
total = sum(v)
top, me = v[-1], v[-2]
x = v[:-2]
m = len(x)

if 2 * (total - top) <= total:
    print("IMPOSSIBLE TO WIN")
else:
    P = [0] * (m + 1)
    for i in range(m):
        P[i + 1] = P[i] + x[i]
    INF = float('inf')
    dp = [INF] * (m + 1)
    dp[0] = 0
    for b in range(1, m + 1):
        for a in range(1, b + 1):
            cost = (b - a + 1) * x[b - 1] - (P[b] - P[a - 1])
            if dp[a - 1] < INF and cost <= P[a - 1]:
                dp[b] = min(dp[b], dp[a - 1] + 1)
    print(min(dp[k] for k in range(1, m + 1) if 2 * (me + P[k]) > total))
