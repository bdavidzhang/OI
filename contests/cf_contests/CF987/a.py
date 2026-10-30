t = int(input())

for _ in range(t):
    n = int(input())
    x = input().split()
    m = {}
    tar = -1
    for c in x:
        d = int(c)
        if(not d in m):
            m[d] = 1
        else:
            m[d] += 1
        if(tar < m[d]):
            tar = m[d]
    print(n-tar)

