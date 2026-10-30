n = int(input())
far = {}
s = input()
for i in range(n):
    far[s[i]] = max(i,far.get(s[i],-1))
mini = int(1e6)
for i in range(n):
    mini = min(mini,i+n-far[s[i]])
print(min(mini,n-1))