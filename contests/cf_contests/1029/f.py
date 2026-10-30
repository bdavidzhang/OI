from math import gcd 

t = int(input())

for _ in range(t):
    p, s = map(int,input().split())
    d = gcd(p,s)
    p //= d
    s //= d
    if p % 2:
        p *= 2
        s *= 2

    out = []
    good = 0
    for a in range(s,50001,s):
        pp = p*a//s 
        hp = pp//2
        w = hp//2
        h = hp-w
        if a >= w+h-1 and a <= w*h:
            for i in range(w):
                    out.append(f"{i} 0")            
                    a -= 1
            for i in range(1,h):
                    out.append(f"0 {i}")
                    a -= 1

            for i in range(1,w):
                for j in range(1,h):
                    if a:
                        out.append(f"{i} {j}")
                        a -= 1
                    else: 
                        break
            good = 1
            break
    
    if good:
        print(len(out))
        print("\n".join(out))
    else:
        print(-1)

