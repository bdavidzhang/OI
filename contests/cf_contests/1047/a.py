t = int(input())

for _ in range(t):
    k,x = (map(int, input().split()))
    for i in range(k):
        x *= 2
    print(x)