import sys


MOD = 998244353


def solve(arr):
	arr.sort()
	size = len(arr)

	fact = 1
	for val in range(2, size):
		fact = fact * val % MOD

	invs = [0] * size
	if size > 1:
		invs[1] = 1
		for val in range(2, size):
			invs[val] = MOD - (MOD // val) * invs[MOD % val] % MOD

	suf_sum = 0
	ans = 0
	for index in range(size - 1, -1, -1):
		if index < size - 1:
			choices = size - index - 1
			ans += (suf_sum - choices * arr[index]) * invs[choices]
			ans %= MOD
		suf_sum += arr[index]

	return ans * fact % MOD


t = int(input())
for _ in range(t):
    n = int(input())
    a = list(map(int,input().split()))
    print(solve(a))


