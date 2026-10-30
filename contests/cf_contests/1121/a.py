t = int(input())

for _ in range(t):
    n = int(input())
    a = list(map(int, input().split()))

    mis = [
        x for i,x in enumerate(a, start=1) if x != i
    ]
    pos = all(
        l > r for l,r in zip(mis, mis[1:])
    )
    print("YES" if pos else "NO")
