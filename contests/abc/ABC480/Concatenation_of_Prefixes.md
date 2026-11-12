<!-- cph-statement -->
# Concatenation of Prefixes

https://atcoder.jp/contests/abc480/tasks/abc480_d

Time limit: 2000 ms, memory limit: 1024 MB

Score : $400$ points

### Problem Statement

You are given an integer sequence $(A_1,\dots,A_N)$ of length $N$.

Construct a sequence $B$ of length $\frac{N(N+1)}{2}$ by the following procedure.

*   Initially, let $B$ be an empty sequence.
*   For $i=1,2,\dots,N$ in this order, append $(A_1,\dots,A_i)$ to the end of $B$.

You are given $Q$ queries of the following form; answer them.

Query: You are given $L$ and $R$. Find $B_L+B_{L+1}+\dots+B_R$.

### Constraints

*   $1 \leq N \leq 10^5$
*   $1 \leq Q \leq 10^5$
*   $-10^8 \leq A_i \leq 10^8$
*   For each query, $1\leq L\leq R \leq \frac{N(N+1)}{2}$.
*   All input values are integers.

* * *

### Input

The input is given from Standard Input in the following format:

```
N Q
A_1 A_2 \dots A_N
\mathrm{query}_1
\mathrm{query}_2
\vdots
\mathrm{query}_Q
```

Here, $\mathrm{query}_i$ represents the $i$\-th query and is given in the following format:

```
L R
```

### Output

Print $Q$ lines.  
The $i$\-th line should contain the answer to the $i$\-th query.

* * *

### Sample Input 1

```
4 3
1 10 100 1000
3 6
1 10
8 8
```

### Sample Output 1

```
121
1234
10
```

$B=(1,1,10,1,10,100,1,10,100,1000)$.

*   The answer to the $1$\-st query is $10+1+10+100=121$.
*   The answer to the $2$\-nd query is $1+1+10+1+10+100+1+10+100+1000=1234$.
*   The answer to the $3$\-rd query is $10$.

* * *

### Sample Input 2

```
7 1
100000000 100000000 100000000 100000000 100000000 100000000 100000000
1 28
```

### Sample Output 2

```
2800000000
```
