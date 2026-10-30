
t = int(input())
for _ in range(t):
    n = int(input())
    # print(n)
    m = [0] * 10
    for i in range(n):
        s = input().split()
        spot = int(s[1])-1
        # print(spot)
        m[spot] = max(m[spot], int(s[0]))
    i = 0
    for val in m:
        if(val == 0):
            print("MOREPROBLEMS")
            i = 1
            break
    if(i == 0):
        print(int(sum(m)))