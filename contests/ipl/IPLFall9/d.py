from math import ceil,sqrt
t = int(input())

def factor(x):
    a = []
    if(x == 1): return [1,1]
    if(x == 2): return [1,2]
    if(x == 3): return [1,3]
    for i in range(1, ceil(sqrt(x))+1):
        if(x % i == 0):
            a.append(int(i))
            a.append(int(x/i))
    return a

for _ in range(t):
    a,b = map(int,input().split())
    if(a <= b):
        print(1)
    else:
        l = factor(a) 
        d = l[0]
        for c in l:
            if(c > d and c <= b):
                d = c
        print(int(a/d))
