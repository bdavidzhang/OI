t = int(input())

for _ in range(t):
  n,c = input().split()
  n = int(n)
  s = input()

  cnt = 0
  i, j = 0, n - 1
  while i < j:
    if s[i] != s[j]:
      cnt += 1 if c in (s[i], s[j]) else 2
    i += 1
    j -= 1

  print(cnt)
  