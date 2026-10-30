from math import sqrt,gcd

N = int(input())
low = int(sqrt(2*N)) - 5 
hi = int(sqrt(2*N)) + 5 
m0 = 0
for m in range(low,hi+1):
  if m <= 0:
    continue
  if N >= m*(m+1) // 2 and N < (m+1) * (m+2) // 2: 
    m0 = m
k = N - m0 *(m0+1) // 2

if k == 0:
  k = m0 - 1
  
  if k == 0:
    print(m0)
  else:
    n = k // gcd(m0,k)
    d = m0 // gcd(m0,k)

    s1 = str(m0)
    s2 = f"{n}/{d}"
    print(" ".join([s1,s2]))
elif k == 1:
  print(m0+1)
else: 
  k = k-1
  m0 = m0 + 1
  n = k // gcd(m0,k)
  d = m0 // gcd(m0,k)

  s1 = str(m0)
  s2 = f"{n}/{d}"
  print(" ".join([s1,s2]))