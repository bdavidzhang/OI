t = int(input())



for _ in range(t):
    n = int(input())
    s = input().strip()

    if n == 1:
        print(s)
    else:
        idx = 0
        potential = s[1]
        def less(s1,s2):
            for i in range(len(s1)):
                if s1[i] > s2[i]:
                    return False
            return True
        for i in range(1,n-1):
            cur = s[0:i] + s[i+1]
            if less(cur,potential):
                potential = cur
                idx = i
        print(idx)
        target = 0
        for j in range(idx,n):
            if s[j] > s[idx]:
                target = j-1
        result = s[0:idx] + s[idx+1:target] + s[idx] + s[target:]
        print(result)

