t = int(input())
for _ in range(t):
  n = int(input())
  ans = [['.']*n for j in range(n)]
  ans[0][1] = 'C'
  ans[1][0] = 'C'
  for line in ans: 
    print("".join(line))
  
# .....
# .....
# .....  
# .....  
# .....  
# if you go -> or |, every anti diagonal 
# is hit exactly once 
# so we can just place at (1,0) and (0,1)
