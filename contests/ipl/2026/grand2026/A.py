# t = int(input())
# for _ in range(t):
n = int(input())
d = {}
for i in range(n):
    s = input()
    d[s[0]] = 1
print(len(d.items()))