tt = int(input())

for _ in range(tt):
    n = int(input())
    nums = list(map(int,input().split(' ')))
    s = sum(nums)
    if s // len(nums) == s / len(nums): 
        oddsum = 0 
        cnt = 0
        for i in range(n):
            if i % 2 == 0:
                oddsum += nums[i]
                cnt += 1
        if oddsum == cnt * s // len(nums):
            print("YES")
        else:
            print("NO")
        
    else:
        print("NO")
