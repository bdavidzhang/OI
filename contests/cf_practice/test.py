N = 3
k = 2
#what is the number of sequences of at least k heads if the probability of heads is equal to p
#we can do inverse counting with k - 1 heads
total = 2**N

dp = [0] * (N+1)

for i in range(k):
    dp[i] = 2**i
for i in range(k,N+1):
    for j in range(1,k):
        dp[i] += dp[i-j];
print(total-dp[N])
