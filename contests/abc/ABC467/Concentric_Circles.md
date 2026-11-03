<!-- cph-statement -->
# Concentric Circles

https://atcoder.jp/contests/abc467/tasks/abc467_d

Time limit: 2000 ms, memory limit: 1024 MB

Score : $425$ points

### Problem Statement

Do there exist two circles $C_1$ and $C_2$ on the $xy$\-plane satisfying all of the following conditions? Here, $C_1$ and $C_2$ may coincide.

*   The two distinct points $(P_x, P_y)$ and $(Q_x, Q_y)$ lie on the circumference of $C_1$.
*   The two distinct points $(R_x, R_y)$ and $(S_x, S_y)$ lie on the circumference of $C_2$.
*   $C_1$ and $C_2$ have the same center.

You are given $T$ test cases; solve each of them.

### Constraints

*   $1 \leq T \leq 5 \times 10^4$
*   $-10^9 \leq P_x,P_y,Q_x,Q_y,R_x,R_y,S_x,S_y \leq 10^9$
*   $(P_x, P_y) \neq (Q_x, Q_y)$
*   $(R_x, R_y) \neq (S_x, S_y)$
*   All input values are integers.

* * *

### Input

The input is given from Standard Input in the following format:

```
T
\mathrm{case}_1
\mathrm{case}_2
\vdots
\mathrm{case}_T
```

Each test case $\mathrm{case}_t$ is given in the following format:

```
P_x P_y Q_x Q_y R_x R_y S_x S_y
```

### Output

Output $T$ lines. The $t$\-th line should contain the answer to the $t$\-th test case.  
For each test case, output `Yes` if there exist two circles $C_1$ and $C_2$ satisfying all of the conditions, and `No` otherwise.

* * *

### Sample Input 1

```
3
2 0 1 1 -1 0 1 2
1 0 -1 0 0 1 0 -1
4 0 3 1 2 0 1 1
```

### Sample Output 1

```
Yes
Yes
No
```

Consider the first test case. As shown in the figure below, if we let $C_1$ be the circle with center $(1,0)$ and radius $1$, and $C_2$ be the circle with center $(1,0)$ and radius $2$, the conditions are satisfied.

For the second test case, letting both $C_1$ and $C_2$ be the circle with center $(0,0)$ and radius $1$ satisfies the conditions.

![image](https://img.atcoder.jp/abc467/18e77104e593467693ed7606ad12956c.png)
