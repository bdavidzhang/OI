n = int(input())

items = [] 
best = {}
ans = 0 

for i in range(n):
    s,p = input().split()
    p = int(p)
    items.append((s,p))    

for i in range(n):
    s,p = items[i]
    if s == "pig":
        if best.get(s,-1) == -1: 
            best[s] = p 
        else: 
            best[s] = max(best[s], p)


for i in range(n):
    s,p = items[i] 
    p = int(p)
    if s != "pig":
        if p < best["pig"]: 
            ans += p 
      
          
print(ans + best["pig"])


    