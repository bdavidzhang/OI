a = input().split()
cnt = {}
ord = {}
for i,w in enumerate(a):
    cnt[w] = cnt.get(w,0) + 1
    if i not in ord:
        ord[w] = i
best = 0
ans = ""
for key in cnt.keys():
    value = cnt[key]
    if value > best:
        best = value
        ans = key
    elif value == best and ord[key] < ord[ans]:
        ans = key

print(ans)



