t = int(input())

for _ in range(t):
  n = int(input())
  arr = list(map(int, input().split()))

  freq = {}
  for x in arr:
    freq[x] = freq.get(x, 0) + 1

  ans = []
  for layer in range(max(freq.values())):
    for x in sorted(freq, reverse=True):
      if freq[x] > layer:
        ans.append(x)

  print(*ans)
