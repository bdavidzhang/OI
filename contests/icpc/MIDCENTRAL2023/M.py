s = input()
cnt = 0
ok = True
i = 0
while(i < len(s)):
    cur = str(cnt)
    if cur == s[i:i+len(cur)]:
        i += len(cur)
    else:
        ok = False
        break
if ok:
    print(k)
else:
    print(-1)