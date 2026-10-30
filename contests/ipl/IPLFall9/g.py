t = int(input())

for _ in range(t):
    n,m,a,b = map(int,input().split())       
    g = [[0 for p in range(m)] for p in range(n)]
    if(n*a == m*b):
        print("YES")
        s = 0
        for d in range(1, m):
            if(d*n) % m == 0:
                s = d
                break
        dx = 0
        for i in range(n):
            for j in range(a):
                g[i][(j+dx) % m] = 1
            dx += s
        for i in range(n):
            for j in range(m):
                print(g[i][j],end='')        
            print()
    else:
        print("NO")
            