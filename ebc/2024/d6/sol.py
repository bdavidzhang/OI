f = open("d6/data.txt","r")
lines = f.read().split('\n')
n = len(lines)

child = {}
parent = {}
for l in lines:
    par = l.split(':')[0]
    children = l.split(':')[1].split(',')
    cl = []
    for c in children:
        cl.append(c)
        if c != '@':
            par.update({c:par})
    parent.append({par:cl})

cur = "RR"
next = ""
q = []
while(not q.empty()):
    #Do
    pass