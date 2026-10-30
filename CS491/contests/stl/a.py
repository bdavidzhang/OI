n = int(input())
s = input().split()
v = [int(a) for a in s]

t = v[0]
ans = t
for i in range(1,n):
    t = max(t+v[i],v[i])
    ans = max(ans,t)
    
print(ans)
    

