def solve(w,d):
  cur = {
    (1,0,0,'A') : 1,
    (0,1,0, 'B1') : 1,
    (0,0,1, 'C') : 1
  }
  dp = [None, cur]
  for L in range (2,w+1):
    nxt = {}
    for (a,b,c, last), v in cur.items():
      if last != 'A':
        k = (a+1, b, c, 'A')
        nxt[k] = nxt.get(k,0) + v
      if last != 'C':
        k = (a, b, c+1, 'C')
        nxt[k] = nxt.get(k,0) + v
      if last != 'B2':
        k = (a, b+1, c, 'B2' if last == 'B1' else 'B1')
        nxt[k] = nxt.get(k,0) + v
    dp.append(nxt)
    cur = nxt 
  ok = lambda a, b, c: max(a,b,c) - min(a,b,c) <= d 
  tot = sum(v for (a,b,c,_), v in dp[w].items() if ok(a,b,c))
  h,pal = (w+1) // 2, 0
  
  for (a,b,c,last), v in dp[h].items():
    if last =='B2':
      continue 
    A,B,C = 2*a, 2*b, 2*c 
    if w % 2 == 0:
      if last != 'B1':
        continue
    else:
      if last == 'A': 
        A -= 1 
      elif last == 'C':
        C -= 1
      else:
        B -= 1
    if ok(A,B,C):
      pal += v 
  return tot - pal 


w,d = map(int,input().split())
print(solve(w,d))
