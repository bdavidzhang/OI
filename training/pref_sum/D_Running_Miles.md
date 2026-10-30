# Running Miles solution

(I realized writing the solution in English flows better with latex)
我们给定一个数组b想找到区间[l,r]上的三个数使得
$$b_m + b_l + b_r - (r-l) = b_m + (b_l + l) - (b_r -r)$$
最大

因此我们可以维护两个数组：
1.一个前缀的最大值数组，对于b[i] + i
2.一个后缀的最大值数组，对于b[i] - i

现在我们只需遍历[1,n-2]中所有的m值来找到最大的。


We can also apply a DP solution to this problem. We 
are still performing the same optimization where we want 
to maximize 
$$b_l + b_m + b_r - (r-l) = (b_l + l) + b_m  + (b_r-r)$$
Now key is that we can use dynamic programming to solve this problem
and more generally up to $k$ numbers. This is the case for $k = 3$.

We define $dp[i][j]$ as the state array, where $i$ represens the solution to the problem on the interval $[0,i]$ and $j$ represents 
the case with the number $j$. 
Essentially, $dp[i][0]$ stores the largest $b_l + l$, $dp[i][1]$
stores the largest $b_m + b_l + l$, and $dp[i][2]$ stores the largest $b_l + l + b_m + b_r -r $, which is the desired answer. 
We can first define the transition from $dp[i][0]$ to $dp[i+1][0]$
when seeing a new number, we can choose to keep or take, if we keep
then dp[i+1][0] = dp[i][0], if we take then dp[i+1][0] = b[i] - i.

Next we define the transition from $dp[i][1]$ to $dp[i+1][1]$,
if we see a new number, we can compare it to the previous state or 
the new state plus the best $b_l + l$, which is represented by 
$b[i] + dp[i][0]$. 

The transition from $dp[i][2]$ to $dp[i+1][2]$ is similar. 

In general, we can use this to find the maximum value for 
$k$ numbers and $k$ corresponding functions $f_k(x)$ over an array. 


