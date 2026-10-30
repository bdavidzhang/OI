t = int(input())
for _ in range(t):
  n,k = list(map(int,input().split()))
  ans = 2 ** (n - k + 1) + 2 * (k - 1)
  print(ans)



