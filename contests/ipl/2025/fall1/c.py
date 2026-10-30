t = int(input())
for _ in range(t):

    n = int(input())
    a = list(map(int, input().split()))
    pref = [0] * n
    large = [0] * n
    pref[0] = a[0]
    large[0] = a[0]

    for i in range(1, n):
        pref[i] = pref[i-1] + a[i]
        large[i] = max(a[i],large[i-1])

    cnt = 0
    
    for i in range(n):
        if pref[i] == 0:
            cnt += 1
        elif large[i] == pref[i] - large[i]:
            cnt += 1

    # print(pref)
    # print(large)
    print(cnt)

