f = open("d1/data3.txt","r")
s = f.read()

#s = "xBxAAABCDxCC"
ans = 0

val = {
    "x" : 0,
    "A" : 0,
    "B" : 1,
    "C" : 3,
    "D" : 5
}

for i in range(len(s)):
    if(i % 3 == 0):
        if(i == len(s)-1):
            ans += val[s[i]]
        p = s[i] + s[i+1] + s[i+2]
        xc = 0
        for c in p:
            if c == 'x': xc+=1
        if(xc == 0):
            ans += 6
        elif(xc == 1):
            ans += 2
        
        ans += val[p[0]]
        ans += val[p[1]]
        ans += val[p[2]]
print(ans)
    