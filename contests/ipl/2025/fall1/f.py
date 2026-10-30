#boss fight


def solve():
    h, n = map(int, input().split())
    a = list(map(int, input().split()))
    c = list(map(int, input().split()))

    def check(k):
        total_damage = 0
        for i in range(n):
            num_uses = (k - 1) // c[i] + 1
            total_damage += num_uses * a[i]
            if total_damage >= h:
                return True
        return False

    low = 1
    high = 4 * 10**10 
    ans = high

    while low <= high:
        mid = (low + high) // 2
        if mid == 0:
            low = 1
            continue
            
        if check(mid):
            ans = mid
            high = mid - 1
        else:
            low = mid + 1
            
    print(ans)

t = int(input())
for _ in range(t):
    solve()