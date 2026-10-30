N, L = map(int,input().split())
ds = map(int,input().split())
pos = {}
if L % 3 != 0:
    print(0)
else:
    pos[0] = 1
    cur = 0
    for d in ds:
        cur = (cur+d) % L
        if pos.get(cur):
            pos[cur] += 1
        else:
            pos[cur] = 1
    ans = 0 
    for cur,num in pos.items():
        cur1 = (cur + L//3) % L
        cur2 = (cur + 2*L//3) % L
        num1 = pos.get(cur1,0)
        num2 = pos.get(cur2,0)
        ans += num*num1*num2
    ans //= 3
    print(ans)