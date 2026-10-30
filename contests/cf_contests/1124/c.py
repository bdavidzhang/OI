def solve(n, k, nums):
	if n < 2 * k - 1:
		return sum(
			max(nums[k + mov - 1], nums[n - k - mov])
			for mov in range(n - k + 1)
		)

	ops_tot = n - 2 * k + 2
	dp = [-1] * (ops_tot + 1)
	dp[0] = 0

	for ops in range(ops_tot):
		next_dp = [-1] * (ops_tot + 1)
		for left_mov in range(ops + 1):
			if dp[left_mov] == -1:
				continue

			right_mov = ops - left_mov
			left_val = nums[k + left_mov - 1]
			right_val = nums[n - k - right_mov]

			next_dp[left_mov + 1] = max(
				next_dp[left_mov + 1],
				dp[left_mov] + left_val,
			)
			next_dp[left_mov] = max(
				next_dp[left_mov],
				dp[left_mov] + right_val,
			)
		dp = next_dp

	overlap_score = sum(
		max(nums[k - 2 - mov], nums[n - k + 1 + mov])
		for mov in range(k - 1)
	)

	return max(dp) + overlap_score


t = int(input())
for _ in range(t):
	n, k = map(int, input().split())
	nums = list(map(int, input().split()))
	print(solve(n, k, nums))
