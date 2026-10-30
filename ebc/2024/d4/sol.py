f = open("d3/data3.txt","r")
lines = f.read().split('\n')
n = len(lines)
m = len(lines[0])

graph = [[0 for _ in range(m+2)] for _ in range(n+2)]

num = 0
for i in range(0,n):
    for j in range(0,m):
        if lines[i][j] == '#':
            graph[i+1][j+1] = -1
            num += 1
            
n += 2
m += 2
for i in range(n):
    print(graph[i]) 
     

dx = [1,0,-1,0,1,1,-1,-1]
dy = [0,1,0,-1,1,-1,1,-1]



def check(x,y,tar):
    for i in range(8):
        if(graph[x+dx[i]][y+dy[i]]) == tar:
            return True
    return False

for i in range(n):
    for j in range(m):
        if graph[i][j] == -1:
            if(check(i,j,0)):
                graph[i][j] = 1
                num -= 1

depth = 1
while num > 0:
    depth += 1
    for i in range(n):
        for j in range(m):
            if graph[i][j] == -1:
                if(check(i,j,depth-1)):
                    graph[i][j] = depth
                    num -= 1

ans = 0
for i in range(n):
    for j in range(m):    
        ans += graph[i][j]


for i in range(n):
    print(graph[i])
print(ans)

                