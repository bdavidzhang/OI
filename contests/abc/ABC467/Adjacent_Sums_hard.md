<!-- cph-statement -->
# Adjacent Sums (hard)

https://atcoder.jp/contests/abc467/tasks/abc467_e

Time limit: 2000 ms, memory limit: 1024 MB

Score : $450$ points

### Problem Statement

**The problem statement of Problem E is the same as Problem C. Only the constraint shown in red differ.**

You are given integer sequences $A=(A_1,A_2,\dots,A_N)$ and $B=(B_1,B_2,\dots,B_{N-1})$ consisting of integers between $0$ and $M-1$, inclusive. The lengths of $A$ and $B$ are $N$ and $N-1$, respectively.  
You can perform the following operation on $A$ any number of times.

*   Choose an integer $i$ with $1 \leq i \leq N$, and add $1$ to $A_i$.

Find the minimum number of operations required to satisfy the following condition.  
It can be proved that the condition can always be satisfied under the constraints of this problem.

*   For $i=1,2,\dots,N-1$, the remainder when $A_i+A_{i+1}$ is divided by $M$ equals $B_i$.

### Constraints

*   $2 \leq N \leq 2 \times 10^5$
*   $3 \leq M \leq 10^9$
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
3 10
4 6 7
5 5
```

### Sample Output 1

```
5
```

If we choose $i=2$ for the first operation, we get $A=(4,7,7)$.  
If we choose $i=1$ for the second operation, we get $A=(5,7,7)$.  
If we choose $i=1$ for the third operation, we get $A=(6,7,7)$.  
If we choose $i=2$ for the fourth operation, we get $A=(6,8,7)$.  
If we choose $i=1$ for the fifth operation, we get $A=(7,8,7)$.  
Since $A_1+A_2=7+8=15$ and $A_2+A_3=8+7=15$, the condition is satisfied.  
The condition cannot be satisfied with four or fewer operations, so the answer is $5$.

* * *

### Sample Input 2

```
2 3
1 2
2
```

### Sample Output 2

```
2
```

* * *

### Sample Input 3

```
10 10
0 1 2 3 4 5 6 7 8 9
9 8 7 6 5 4 3 2 1
```

### Sample Output 3

```
40
```
