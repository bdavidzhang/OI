t = int(input())
for _ in range(t):
    n = int(input())
    x = input().split()
    ec = oc = 0
    a = []
    for c in x:
        d = int(c)
        if(d % 2 == 0): ec += 1
        else: oc += 1
        a.append(d)
    if(oc % 2 == 0 and ec % 2 == 0):
        print("YES")
    elif(oc % 2 == 1 and ec % 2 ==1):
        a.sort()
        check = False
        for i in range(n-1):
            if(a[i+1] == a[i] + 1):
                check = True
        if(check): 
            print("YES")
        else:
            print("NO")
    else:
        print("NO")



    