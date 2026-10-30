import sys 
from collections import deque

def solve():
  data = sys.stdin.read().split()
  n = int(data[0])
  g,k = [], 1
  for i in range(n):
    row = [int(x) for x in data[k:k + i + 1]]
    k += i + 1
    g.append([None if x == 100 else x for x in row])
    
  q = deque((i,j) for i in range(n-1) for j in range(i+1))

  while q:
    i,j = q.popleft()
    t,l,r = g[i][j], g[i+1][j], g[i+1][j+1]
    unk = (t is None) + (l is None) + (r is None)
    if unk == 0:
      if t != l + r:
        print("no solution")
        return 
      continue
    if unk > 1:
      continue
    # unk == 1
    if t is None:
      a,b,v = i,j,l+r 
    elif l is None:
      a,b,v = i+1, j, t-r 
    else: 
      a,b,v = i+1, j+1, t-l
    if abs(v) > 99:
      print("no solution")
      return
    g[a][b] = v 
    if a < n-1:
      q.append((a,b))
    if a >= 1 and b <= a - 1:
      q.append((a-1,b))
    if a >= 1 and b >= 1:
      q.append((a-1,b-1))
  if any(x is None for row in g for x in row):
    print("ambiguous")
    return
  print('\n'.join(["solvable"] + [" ".join(map(str,r)) for r in g]))
      
solve()