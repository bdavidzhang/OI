# m * b_m - (b1 + ... b_(m-1))
import heapq
t = int(input())

for _ in range(t):
    n, m = map(int, input().split())
    a = list(map(int, input().split()))

    mini = []
    smtot = 0
    ans = None

    for x in a:
        if len(mini) == m - 1:
            score = m * x - smtot
            if ans is None or score > ans:
                ans = score

        if m > 1:
            if len(mini) < m - 1:
                heapq.heappush(mini, -x)
                smtot += x
            elif x < -mini[0]:
                maxi = -heapq.heapreplace(mini, -x)
                smtot += x - maxi

    print(ans)
