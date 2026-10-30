t = int(input())
for _ in range(t):
  n, m = list(map(int,input().split()))
  
  ok = True
  cnt = 0
  for i in range(m):  
    a, b = list(map(int,input().split()))
    if a > b: 
      ok = False
    if b == a+1:
      cnt += 1
  if ok:
    print((n-1) - cnt)
  else:
    print(-1)
  
# can be seen as a dag
# (a,b) means a comes before b
# we need to ensure that it has a unique toposort
# then there has to be chain dependency

    
    