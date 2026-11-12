idea is time is max over k of (sum_{i}^k A_i + Bk)
A1 + B1
A1 + A2 + B2
if B1 is really long, then it contains A2 + B2
if A2 is really long, then it dominates the result

so on the interval l,r 
sum stores the sum of A_i
and then best is the max value on this interval 
for two intervals, merging means sum = sum_l + sum_r, 
best = max(best_l, sum_l + best_r)


