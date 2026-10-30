import re
f = open("d2/data3.txt","r")
lines = f.read().split('\n')

words = lines[0].split(':')[1].split(',')
words += [t[::-1] for t in words]
ans = 0
checked = [[0]*len(lines[2])]*(len(lines)-2)
print(len(checked))
print(len(checked[0]))
n = len(checked)
m = len(checked[0])

for i in range(n):
    for j in range(m):
        p = ""
        for k in range(m):
            p += lines[i+2][(j+k)%m]
            if p in words:
                checked
        

           


                