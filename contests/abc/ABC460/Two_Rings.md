<!-- cph-statement -->
# Two Rings

https://atcoder.jp/contests/abc460/tasks/abc460_b

Time limit: 2000 ms, memory limit: 1024 MB

Score : $250$ points

### Problem Statement

There are two circles $C_1$ and $C_2$ on the $xy$\-plane. In this problem, a circle refers to the circumference.  
Circle $C_1$ has its center at $(X_1, Y_1)$ and radius $R_1$.  
Circle $C_2$ has its center at $(X_2, Y_2)$ and radius $R_2$.  
Determine whether circles $C_1$ and $C_2$ have a common point. In other words, determine whether there exists at least one point whose distance from $(X_1, Y_1)$ is $R_1$ and whose distance from $(X_2, Y_2)$ is $R_2$.

You are given $T$ test cases; solve each one.

### Constraints

*   $1 \leq T \leq 100$
*   $0 \leq X_1, Y_1, X_2, Y_2 \leq 10^9$
*   $1 \leq R_1, R_2 \leq 10^9$
*   All input values are integers.

* * *

### Input

The input is given from Standard Input in the following format, where $\mathrm{case}_i$ denotes the $i$\-th test case:

```
T
\mathrm{case}_1
\mathrm{case}_2
\vdots
\mathrm{case}_T
```

Each test case is given in the following format:

```
X_1 Y_1 R_1 X_2 Y_2 R_2
```

### Output

Output $T$ lines. The $i$\-th line should contain the answer for the $i$\-th test case.  
For each test case, output `Yes` if circles $C_1$ and $C_2$ have a common point, and `No` otherwise.

* * *

### Sample Input 1

```
7
0 0 2 2 3 2
0 0 2 2 3 1
1 2 5 3 2 1
5 4 2 8 8 3
2 1 5 5 1 2
0 0 1 0 0 1
0 0 500000000 1 1000000000 500000000
```

### Sample Output 1

```
Yes
No
No
Yes
Yes
Yes
No
```

For example, in the first test case, the relative positions of $C_1$ and $C_2$ are as shown in the following figure.

![image](https://img.atcoder.jp/abc460/c50e9b9b9195362578cdf6b5a9de6204.png)
