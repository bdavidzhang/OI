t = int(input())
for _ in range(t):
    n,m = map(int, input().split())
    maxr = maxw = 0
    for i in range(m):
        r,w = map(int, input().split())
        maxr = max(maxr,r)
        maxw = max(maxw,w)
    if maxr + maxw > n:
        print("IMPOSSIBLE")
    else:
        print("R"*maxr + "W"*maxw+"W"*(n-maxr-maxw))
        