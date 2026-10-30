n = int(input())
a = sorted(list(map(int,input().split())))
b = []
j = n-1
k = 0
for i in range(n):
    if(i % 2 ==0):
        b.append(str(a[j]))
        j -= 1
    else:
        b.append(str(a[k]))
        k += 1
print(" ".join(b))
