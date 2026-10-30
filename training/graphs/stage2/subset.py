def A_subset(A,n):
    ans = 0
    lis = []
    for i in range(n):
        lis.append(A[i])

    ans = sum(A)
    return (ans,lis)

if __name__ == "__main__":
    n = 3
    A = [67,12,2,22,1,90,48,72,94,3]
    print(A_subset(A,n))


