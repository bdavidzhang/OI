from math import *
f = open("d4/data3.txt","r")
lines = f.read().split('\n')

a = []
for i in range(len(lines)):
    a.append(int(lines[i]))

print(a)
a.sort()
ans = 0
pivot = ceil(len(a)/2)
for i in range(0,len(a)):
    if(i != pivot):
        ans += abs(a[i]-a[pivot])

print(ans)