n = int(input())
t = input().strip()
a = input().strip()

good = 0
for i in range(n):
    if t[i] == a[i] == 'o':
        good = 1
        break
    
if good:
    print("Yes")
else:
    print("No")