<!-- cph-statement -->
# Mod While Positive

https://atcoder.jp/contests/abc460/tasks/abc460_a

Time limit: 2000 ms, memory limit: 1024 MB

Score : $100$ points

### Problem Statement

You are given positive integers $N$ and $M$.

If the following operation is repeated while the value of $M$ is not $0$, find the number of operations performed.

*   Let $x$ be the remainder when $N$ is divided by $M$. Replace the value of $M$ with $x$.

It can be proved that $M$ becomes $0$ after a finite number of operations.

### Constraints

*   $1 \leq N, M \leq 1000$
*   All input values are integers.

* * *

### Input

The input is given from Standard Input in the following format:

```
N M
```

### Output

Output the answer.

* * *

### Sample Input 1

```
8 5
```

### Sample Output 1

```
3
```

Initially, $N = 8$ and $M = 5$.

The remainder when $8$ is divided by $5$ is $3$, so $M = 3$ after one operation.

The remainder when $8$ is divided by $3$ is $2$, so $M = 2$ after two operations.

The remainder when $8$ is divided by $2$ is $0$, so $M = 0$ after three operations.

Thus, output $3$ as the answer.

* * *

### Sample Input 2

```
14 6
```

### Sample Output 2

```
2
```

* * *

### Sample Input 3

```
460 33
```

### Sample Output 3

```
5
```
