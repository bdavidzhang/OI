from math import sqrt,floor
t = int(input())

for _ in range(t):
    num = int(input())
    if sqrt(num) != int(sqrt(num)):
        print(-1)
    else: 
        print(f"{0} {int(sqrt(num))}")
        