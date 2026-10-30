t = int(input())

for _ in range(t):
    n = int(input())
    a = list(map(int, input().split())) 


    q = [n - x + 1 for x in a]
    
    print(' '.join(map(str, q)))