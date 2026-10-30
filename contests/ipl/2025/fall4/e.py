def solve():
    d,k = map(int,input().split())
    lo = 0
    hi = int(1e5)
    idx = 0
    while(lo <= hi):
        mid = int(lo + (hi-lo)//2)
        if(2*mid*mid*k*k <= d*d):
            lo = mid + 1
            idx = mid
        else:
            hi = mid-1
    c = idx*k

    # print(c)
    # print(idx)
    if(c*c + (c+k)*(c+k) <= d*d):
        print("Ashish")
    else:
        print("Utkarsh")

if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        solve()
    
