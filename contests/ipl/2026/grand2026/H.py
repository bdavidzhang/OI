import heapq

n, K = map(int, input().split())
a = list(map(int, input().split()))
b = list(map(int, input().split()))
#sort a List
inc = [0] * n
# s = [(a[i],b[i], i) for i in range(n)].sort().reverse()
s= [(a[i],b[i], i) for i in range(n)]
s = sorted(s)[::-1]

pq = []
tot = 0
l = 0
for i in range(n):
    if s[i][1] == 2:
        if tot + s[i][0] >= K*(l+1):
            inc[i] = 1
            tot += s[i][0]
            l += 1
            heapq.heappush(pq,s[i])
    
maxl = l    
for i in range(n):
    if b[i] == 2:
        if(inc[i] == 1):
            inc[i] = 0
            tot -= a[i]
            l -= 1
        continue
    elif (tot + a[i] >= K*(l+1)) and b[i] == 1:
        tot += a[i]
        l += 1
        if(l > maxl):
            maxl = l
    elif(len(pq) > 0):
        cur = pq[0]
        while(inc[cur[2]] == 0 and len(pq) > 0):
            heapq.heappop(pq)
            if(len(pq) > 0):
                cur = pq[0]
        if (len(pq) > 0) and (a[i] > cur[0]):
            tot -= cur[0]
            tot += a[i]
            inc[cur[2]] = 0
            heapq.heappop(pq)
            heapq.heappush(pq,(a[i],b[i], i))
print(maxl)
print(pq)
     