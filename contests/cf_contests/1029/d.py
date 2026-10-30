t = int(input())

for _ in range(t):
    out = []
    n,m  = map(int,input().split(' '))
    a = sorted(map(int,input().split(' ')))

    seen = [0] * m
    order = []    
    for i in range(n):
        if not seen[i]:
            seen[i] = 1
            order.append(i)
        if not seen[~i]:
            seen[~i] = 1
            order.append(~i)
    
    for j in range(n):
        u = order[j]
        l = [a[u],a[~u]]*3
        out.append(l)
    
    for l in out:
        s = ""
        for p in l:
            s += str(p) + " " 
        print(s)
