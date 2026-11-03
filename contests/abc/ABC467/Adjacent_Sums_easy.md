<!-- cph-statement -->
# Adjacent Sums (easy)

https://atcoder.jp/contests/abc467/tasks/abc467_c

Time limit: 2000 ms, memory limit: 1024 MB

Score : $300$ points

### Problem Statement

**The problem statement of Problem C is the same as Problem E. Only the constraint shown in red differ.**

You are given integer sequences $A=(A_1,A_2,\dots,A_N),B=(B_1,B_2,\dots,B_{N-1})$ consisting of integers between $0$ and $M-1$, inclusive. The lengths of $A$ and $B$ are $N$ and $N-1$, respectively.  
You can perform the following operation on $A$ any number of times.

*   Choose an integer $i$ with $1 \leq i \leq N$, and add $1$ to $A_i$.

Find the minimum number of operations required to satisfy the following condition.  
It can be proved that the condition can always be satisfied under the constraints of this problem.

*   For $i=1,2,\dots,N-1$, the remainder when $A_i+A_{i+1}$ is divided by $M$ equals $B_i$.

### Constraints

*   $2 \leq N \leq 2 \times 10^5$
*   $M=2$
*   $0 \leq A_i \leq M-1$
*   $0 \leq B_i \leq M-1$
*   All input values are integers.

* * *

### Input

The input is given from Standard Input in the following format:

```
N M  
A_1 A_2 \ldots A_N
B_1 B_2 \ldots B_{N-1}
```

### Output

Output the answer on one line.

* * *

### Sample Input 1

```
3 2
1 1 1
1 1
```

### Sample Output 1

```
1
```

If we choose $i=2$ for the first operation, we get $A=(1,2,1)$.  
Since $A_1+A_2=1+2=3$ and $A_2+A_3=2+1=3$, the condition is satisfied.  
$A=(1,1,1)$ does not satisfy the condition, so the answer is $1$.

* * *

### Sample Input 2

```
2 2
1 1
0
```

### Sample Output 2

```
0
```

* * *

### Sample Input 3

```
10 2
0 0 0 1 1 0 1 0 1 0
0 1 0 1 0 1 0 1 0
```

### Sample Output 3

```
4
```
