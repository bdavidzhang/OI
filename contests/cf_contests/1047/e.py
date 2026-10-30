t = int(input())

for _ in range(t):
    n, k = map(int,input().split()) 

    a = list(map(int,input().split()))
    
    b = sorted(a)
    m = 0
    idx = -1
    if b[0] > 0:
        m = 0
    else:
        for i in range(1,n):
            if b[i] - b[i-1] > 1:
                m = b[i-1] + 1
                idx = i
                break 
        if idx == -1:
            m = b[n-1] + 1
    # now we want to consider the few cases:
    #1. m = n, the array is a permutation
    ans = 0
    if m == n and set(range(n)) == set(b):
        ans = n*(n-1) // 2
    #2. 0,1, ... n - 2, n, this would result in b[n-2] == n-2 and b[n-1] == n
    elif b[n-2] == n-2 and b[n-1] == n and m == n-1:
        for i in range(n):
            ans = n*(n-1) // 2
    #3. m == 0, in this case everything turns into zero
    #this can go into the second case because they infact alternate
    #4. there is more than one integer larger than m and m >= 1
    else:
        count = {}
        for i in range(n):
            count[b[i]] = count.get(b[i],0) + 1
        for i in range(n):
            if count[b[i]] > 1 or b[i] > m:
                b[i] = m
        ans1 = sum(b)
        # print(b)
        if k == 1:
            ans = ans1
        else:
            m = 0
            idx = -1
            if b[0] > 0:
                m = 0
            else:
                for i in range(1,n):
                    if b[i] - b[i-1] > 1:
                        m = b[i-1] + 1
                        idx = i
                        break 
                if idx == -1:
                    m = b[n-1] + 1
            # now we want to consider the few cases:
            #1. m = n, the array is a permutation
            if m == n and set(range(n)) == set(b):
                ans = n*(n-1) // 2
            #2. 0,1, ... n - 2, n, this would result in b[n-2] == n-2 and b[n-1] == n
            elif b[n-2] == n-2 and b[n-1] == n and m == n-1:
                for i in range(n):
                    ans = n*(n-1) // 2
            #3. m == 0, in this case everything turns into zero
            #4. there is more than one integer larger than m and m >= 1
            else: 
                count = {}
                for i in range(n):
                    count[b[i]] = count.get(b[i],0) + 1
                for i in range(n):
                    if count[b[i]] > 1 or b[i] > m:
                        b[i] = m
                ans2 = sum(b)
                # print(b)
                if k == 2:
                    ans = ans2
                else:
                    m = 0
                    idx = -1
                    if b[0] > 0:
                        m = 0
                    else:
                        for i in range(1,n):
                            if b[i] - b[i-1] > 1:
                                m = b[i-1] + 1
                                idx = i
                                break 
                        if idx == -1:
                            m = b[n-1] + 1
                    if m == n and set(range(n)) == set(b):
                        ans = n*(n-1) // 2
                    elif b[n-2] == n-2 and b[n-1] == n and m == n-1:
                        for i in range(n):
                            ans = n*(n-1) // 2
                    else: 
                        count = {}
                        for i in range(n):
                            count[b[i]] = count.get(b[i],0) + 1
                        for i in range(n):
                            if count[b[i]] > 1 or b[i] > m:
                                b[i] = m
                        ans1 = sum(b)
                        ans = ans2 if k % 2 == 0 else ans1
    print(ans)
            
    
        
        
    
    