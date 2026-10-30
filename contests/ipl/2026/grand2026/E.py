t = int(input())

yes = "Alice"
no = "Bob"

def largest2(num):
    if num % 2 != 0: return 1
    factor = 0
    while num % 2 == 0:
        num /= 2
        factor += 1
    return 2 ** factor

for _ in range(t):
    n,k = map(int,input().split())
    # print("-"*10)
    if k >= n:
        print(yes)
    elif n % 2 == 1:
        print(yes)
    else:
        num = largest2(n)
        # print(num)
        if num <= k:
            print(yes)
        else:
            print(no)
        
