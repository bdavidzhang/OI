n, k = list(map(int,input().split()))

hours = [[0] for i in range(25)]


for _ in range(n):
    a, b = list(map(int,input().split()))
    for j in range(a,b):
        hours[j] += 1

cnt = 0
for v in hours:
    if v >= k:
        cnt += 1

print(hours)
print(cnt)

