#much easier than I thought

t = int(input())

for _ in range(t):
    n,m = (map(int,input().split(' ')))
    out = []
    a = b = 1
    for _ in range(n):
        a, b = b,a+b
    for _ in range(m):
        *z, = map(int,input().split(' '))

        if min(z) >= a and max(z) >= b:
            out.append('1') 
        else:
            out.append('0')
    print("".join(out))
    
        