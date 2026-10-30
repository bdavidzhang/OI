t = int(input())

for _ in range(t):
    n,m = map(int, input().split())
    x1,y1 = -1,-1
    x2,y2 = -1,-1
    for i in range(n):
        s = input()
        for j in range(m):
            if s[j] == '#':
                if x1 == -1:
                    x1,y1 = j,i
                x2,y2 = j,i
    print((y1+y2)//2+1, x1+1)