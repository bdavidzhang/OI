tt = int(input())

for _ in range(tt):
    n,m = (map(int,input().split(' ')))
    x = 0 
    ans = 0
    lens = []
    for i in range(n):
        word = input()
        lens.append(len(word))
    for i in range(n):
        if ans + lens[i] <= m:
            ans += lens[i]
            x += 1
        else:
            break
    print(x)
   
