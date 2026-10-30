t = int(input())

for _ in range(t):
    n = int(input())
    arr = (list(input().split(" ")))
    arr = sorted([int(a) for a in arr])
    cntmin = cntmax = 0
    for i in range(len(arr)):
        if (arr[i] + arr[-1]) % 2 != 0:
            cntmin += 1
        else: 
            break
    for j in reversed(range(len(arr))):
        if (arr[0] + arr[j]) % 2 != 0:
            cntmax += 1
        else: 
            break
    print(min(cntmin,cntmax))



