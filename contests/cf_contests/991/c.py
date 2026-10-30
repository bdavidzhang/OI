tt = int(input())

for _ in range(tt):
    n = input() 
    ans = 0
    nlist = []
    num2 = 0
    num3 = 0
    for i in range(len(n)):
        ans += int(n[i])
        nlist.append(int(n[i]))
        if n[i] == '2':
            num2 += 1
        elif n[i] == '3':
            num3 += 1
    ans = ans % 9 
    two_list = [0,2,4,6,8,1,3,5,7]
    three_list = [0,6,3]
    if ans == 0:
        print("YES")
    else: 
        if(num2 < 9):
            m2 = two_list[:num2+1]
        else:
            m2 = two_list
        if(num3 < 3):
            m3 = three_list[:num3+1]
        else:
            m3 = three_list
        m23 = []
        for a in m2:
            for b in m3:
                m23.append(a+b)
        flag = False
        for x in m23:
            if (ans + x) % 9 == 0:
                flag = True
                break
        if flag:
            print("YES")
        else: 
            print("NO")
