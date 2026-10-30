t = int(input())
for _ in range(t):
  n = int(input())
  cnt1 = cnt2 = cnt3 = cnt4 = 0
  arr = list(map(int,input().split()))
  for x in arr: 
    if 1 <= x <= 10: 
      cnt1 = 1
    elif 11 <= x <= 20:
      cnt2 = 1
    elif 21 <= x <= 30:
      cnt3 = 1
    elif 31 <= x <= 40:
      cnt4 = 1
  print(cnt1+cnt2+cnt3+cnt4)