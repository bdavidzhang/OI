t = int(input())

for _ in range(t):
    n,k = (int(a) for a in input().split(" "))
    s = input()
    zcnt = ocnt = 0
    for i in range(len(s)):
        if s[i] == '0':
            zcnt += 1
        else:
            ocnt += 1
    lowb = int((max(zcnt,ocnt) - min(zcnt,ocnt))/2)
    upb = zcnt // 2 + ocnt // 2
    if k < lowb or k > upb:
        print('NO')
    else:
        if (k - lowb) % 2 != 0:
            print("NO")
        else:
            print("YES")