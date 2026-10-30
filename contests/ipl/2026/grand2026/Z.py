t = int(input())
for _ in range(t):
    # print("-"*10)
    n = int(input())
    s = input()
    ans = ""
    for i in range(n):
        # cur = s[i:i+n]
        ans += '1' if s[2*i] == '0' else '0'
    print(ans)

