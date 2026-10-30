s = input()

ok = True
for i in range(len(s)-1):
    if s[i] == 'O' and s[i+1] == 'O':
        ok = False
        break

if not ok:
    print("INVALID")

def solve():
    
