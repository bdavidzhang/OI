n = int(input())

results = []
for i in range(200):
    results.append([0,0])
# print(results)
# print(len(results))
results[1][0] = 1
results[1][1] = 0
results[2][0] = 0
results[2][1] = 1

for i in range(3,200):
    results[i][0] = (results[i-1][0] + results[i-2][0])/2
    results[i][1] = (results[i-1][1] + results[i-2][1])/2

if n <= 150:
    print(f"{results[n][0]*100:.10f} {results[n][1]*100:.10f}")
else:
    print(f"{1/3*100:.10f} {2/3*100:.10f}")
    

