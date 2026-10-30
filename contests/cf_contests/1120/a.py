t = int(input())
for _ in range(t):
    n = int(input())
    a = list(map(int,input().split()))
    cnt1 = 0
    for x in a:
        if x == 1:
            cnt1 += 1
    cnt0 = len(a) - cnt1
    if cnt1 >= cnt0:
        print("Bessie")
    else:
        print("Elsie")
        
        