t = int(input())

for _ in range(t):
    a,b = map(int, input().split())

    if b % 2 != 0 and a % 2 != 0:
        print(a*b + 1)
    elif b % 2 != 0 and a % 2 == 0:
        print(-1)
    elif b % 2 == 0 and a % 2 != 0:
        if b % 4 == 0:
            print(2 + a*b//2)    
        else:
            print(-1)
    elif b % 2 ==0 and a % 2 == 0:
        print(2 + a*b//2)