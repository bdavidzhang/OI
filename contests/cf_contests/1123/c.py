t = int(input())

for _ in range(t):
  n, x = map(int, input().split())
  arr = list(map(int, input().split()))

  ps = []
  d = 2
  r = x
  while d * d <= r:
    if r % d == 0:
      ps.append(d)
      while r % d == 0:
        r //= d
    d += 1
  if r > 1:
    ps.append(r)

  ans = 0
  for p in ps:
    ans = max(ans,sum(x for x in arr if x % p == 0))

  print(ans)

