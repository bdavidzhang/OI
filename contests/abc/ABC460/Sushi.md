<!-- cph-statement -->
# Sushi

https://atcoder.jp/contests/abc460/tasks/abc460_c

Time limit: 2000 ms, memory limit: 1024 MB

Score : $300$ points

### Problem Statement

There are $N$ pieces of shari (vinegared rice) and $M$ pieces of neta (toppings) as ingredients for sushi.

The weight of the $i$\-th shari is $A_i$, and the weight of the $j$\-th neta is $B_j$.

You will make sushi by combining shari and neta.

To make one piece of sushi, you need to combine one shari with one neta. Here, the weight of the neta must be at most twice the weight of the shari. Also, the same shari or neta cannot be used in multiple pieces of sushi.

Find the maximum number of sushi that can be made.

### Constraints

*   $1 \leq N, M \leq 2 \times 10^5$
*   $1 \leq A_i, B_j \leq 10^9$
*   All input values are integers.

* * *

### Input

The input is given from Standard Input in the following format:

```
N M
A_1 A_2 \ldots A_N
B_1 B_2 \ldots B_M
```

### Output

Output the answer.

* * *

### Sample Input 1

```
4 5
4 2 1 8
14 9 3 2 9
```

### Sample Output 1

```
3
```

By combining the $1$st shari with the $3$rd neta, the $2$nd shari with the $4$th neta, and the $4$th shari with the $1$st neta, for example, you can make three pieces of sushi. It is impossible to make four or more pieces of sushi, so output $3$.

* * *

### Sample Input 2

```
3 3
5 5 3
11 1000 1000
```

### Sample Output 2

```
0
```

* * *

### Sample Input 3

```
8 7
2 3 4 4 4 3 2 3
8 5 5 9 9 7 1
```

### Sample Output 3

```
5
```
