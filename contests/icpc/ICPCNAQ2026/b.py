
n = int(input())
arr = []
for i in range(n):
  x = int(input())
  arr.append(x)

cnt = 0
for t in range(1,n-1):
  if (arr[t] - arr[t-1]) > (arr[t+1] - arr[t]):
    cnt += 1
print(cnt) 
