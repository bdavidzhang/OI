T = int(input())
for _ in range(T):
  n, p = list(map(int,input().split()))
  ts = list(map(int,input().split()))
  print(p*p / sum(ts))
  
  
#using cauchy schwartz
#let ai = x_i / sqrt(s_i), bi = sqrt(si)
#then a cdot b = sum x, 
# and |a| = sum xi^2 / si, |b| = sum(si) 
# (square rooted)
#so answer >= (sum x)^2/(sum s) = P^2/T
  
  
