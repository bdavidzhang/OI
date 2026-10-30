from math import sqrt
n = int(input())
for _ in range(n):
  x = int(input())
  sq = 0
  o = 0
  for k in range(0,int(sqrt(x)) + 3):
    if k * k == x:
      sq = 1
  if x % 2 == 1:
    o = 1
  if sq == 1 and o == 1:
    print("OS")
  elif sq == 1:
    print("S")
  elif o == 1:
    print("O")
  else:
    print("EMPTY")