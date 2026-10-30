t = int(input())
for _ in range(t):
    n = int(input())
    b = [0] + list(map(int,input().split()))
    pref = [0] * (n+1)
    suf = [0] * (n+1)
    tot = sum(b)
    for i in range(1,n+1):
        pref[i] = pref[i-1] + b[i]
        suf[i] = tot-pref[i]
    mini = int(1e20)
    idx = -1
    for j in range(1,n):
        if(pref[j] == suf[j]):
            mini = 0
            idx = j
            break
        if 2*j - n == 0:
            continue
        else:
            val = -1*(suf[j]-pref[j])//(n-2*j)
            if val < 0 or (suf[j]-pref[j]) % (n-2*j) != 0:
                continue
            else:
                mini = min(mini,val)
                idx = j
    # print("-"*10)
    # print(pref)
    # print(suf)
    if idx == -1:
        print(-1)
    else:
       print(mini)