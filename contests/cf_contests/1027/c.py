t = int(input())

for _ in range(t):
    n = int(input())
    arr = [int(a) for a in input().split(" ")]
    dp = []
    dp.append((arr[0],1)) #element, num
    for i in range(1,n):
        ele, num = dp[i-1]
        if arr[i] - ele >= 2:
            dp.append((arr[i],num+1))
        else:
            dp.append((ele,num))
    ele,num = dp[n-1]
    print(num)
