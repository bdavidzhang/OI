def minOperations(nums):
    """
    :type nums: List[int]
    :rtype: int
    """

    n = len(nums)
    val = nums[0]
    for i in range(1,n):
        val = nums[i] & val

    lidx = 0
    ridx = n-1
    while(lidx <= n-1 and nums[lidx] == val):
        lidx+=1
    while(ridx >= 0 and nums[ridx] == val):
        ridx-=1

        
    # print(f"val: {val}")
    # print(f"lidx: {lidx}")
    # print(f"ridx: {ridx}")


    tot = nums[lidx]
    for i in range(lidx+1, ridx):
        tot = nums[i] & tot 

    if lidx == n and ridx == -1:
        return 0
    elif tot != val:
        return ridx - lidx + 1
    else:
        return ridx - lidx



        
if __name__ == "__main__":
    t1 = [3,7,39,3]
    print(minOperations(t1))
    # print(minOperations(t2))

        