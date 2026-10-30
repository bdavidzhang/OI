import random
import sys
random.seed(67) 
random.seed(691) #good prime
ramdom.seed(42)
random.seed(114514)


t = int(input())
for _ in range(t):
  for i in range(100):
    res = random.choice(['T','F'])
    print(res,flush=True)
    real = input()
    if real == '-1':
      sys.exit(0)
    if real == 'T':
      nxt = 'F'
    else:
      nxt = 'T'
    print(nxt,flush=True)
    fake = input()

      
      
      