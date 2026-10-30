t = int(input())
for _ in range(t):
    n, k = map(int, input().split())
    if k < n or k == 2*n:
        print(-1)
        continue
    d = k - n
    res = [[0] * n for _ in range(n)]
    cnt = 1
    for i in range(d,n):
        res[i][i] = cnt
        cnt += 1
    for i in range(d):
        res[i][d] = i + cnt
        res[d][i] = d + i + cnt
    cnt += 2*d
    for i in range(n):
        for j in range(n):
            if res[i][j] == 0:
                res[i][j] = cnt 
                cnt += 1
    for y in res: 
        print(" ".join(map(str, y)))
    
    
