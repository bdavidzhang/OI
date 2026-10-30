t = int(input())
for _ in range(t):
  p,q,g = list(map(int,input().split()))
  ptog = {}
  cnt = {}
  for j in range(q):
    s = input().split()
    if s[0] == 'P':
      arr = list(map(int,s[1:]))
      cur = arr[0]
      a = arr[1] 
      for i in range(a):
        x = arr[i+2]
        if ptog[x] in cnt:
          cnt[ptog[x]] -= 1
        ptog[x] = cur
        cnt[cur] += 1
    else:
      a = int(s[1])
      print(cnt[a])
