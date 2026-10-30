#26^3 < 30^3 = 27000


chars = []
for i in range(26):
    chars.append(chr(ord('a')+i))
print(chars)

#case 2
# strs1 = []
# for x in chars:
#     for y in chars:
#             strs1.append(x+y)   
# # print(len(strs1))


# cnt1 = 0 
# for s in strs1:
#     if s[0] <= s[1]:
#         pass
#     elif s[0] >= s[1]:
#         pass
#     else:
#         cnt1 += 1

# print(cnt1)


#case 3
strs1 = []
for x in chars:
    for y in chars:
        for z in chars:
            strs1.append(x+y+z)   
# print(len(strs1))

cnt1 = 0 
a = 0
for s in strs1:
    if s[0] <= s[1] <= s[2]:
        a += 1
    elif s[0] >= s[1] >= s[2]:
        pass
    else:
        cnt1 += 1

print(cnt1)
print(cnt1 == 26**3 - 2*a + 26)

#case 4
strs2 = []
for x in chars:
    for y in chars:
        for z in chars:
            for w in chars:
                strs2.append(x+y+z+w)   
# print(len(strs2))

cnt2 = 0 
for s in strs2:
    if s[0] <= s[1] <= s[2] <= s[3]:
        pass
    elif s[0] >= s[1] >= s[2] >= s[3]:
        pass
    else:
        cnt2 += 1

print(cnt2)
        


#case 5
strs3 = []
for x in chars:
    for y in chars:
        for z in chars:
            for w in chars:
                for m in chars:
                    strs3.append(x+y+z+w+m)   
# print(len(strs3))

cnt3 = 0 
for s in strs3:
    if s[0] <= s[1] <= s[2] <= s[3] <= s[4]:
        pass
    elif s[0] >= s[1] >= s[2] >= s[3] >= s[4]:
        pass
    else:
        cnt3 += 1

print(cnt3)

print(cnt1+cnt2+cnt3)