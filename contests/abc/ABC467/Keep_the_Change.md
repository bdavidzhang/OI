<!-- cph-statement -->
# Keep the Change

https://atcoder.jp/contests/abc467/tasks/abc467_b

Time limit: 2000 ms, memory limit: 1024 MB

Score : $200$ points

### Problem Statement

Takahashi made purchases at $N$ stores. Initially, he had $10000$ yen.  
At the $i$\-th store, he bought an item worth $A_i$ yen and paid $B_i$ yen. Here, $A_i \leq B_i$ holds. If $S_i =$ `keep`, he did not receive the change, and if $S_i =$ `take`, he received the change.  
Find the amount of money he lost compared to the case where he received the change at every store. To be precise,

*   let $X$ yen be Takahashi's final amount of money, and
*   let $Y$ yen be Takahashi's final amount of money in the case where he received the change at every store.

Find $Y - X$.

### Constraints

*   $1 \leq N \leq 100$
*   $1 \leq A_i \leq B_i \leq 100$
*   $S_i$ is `keep` or `take`.
*   $N, A_i, B_i$ are all integers.

* * *

### Input

The input is given from Standard Input in the following format:

```
N
A_1 B_1 S_1
A_2 B_2 S_2
\vdots
A_N B_N S_N
```

### Output

Output the amount of money Takahashi lost compared to the case where he received the change at every store.

* * *

### Sample Input 1

```
3
1 2 keep
3 6 take
5 9 keep
```

### Sample Output 1

```
5
```

Takahashi's actions are as follows.

*   At the first store, he bought an item worth $1$ yen, paid $2$ yen, and did not receive the change.
*   At the second store, he bought an item worth $3$ yen, paid $6$ yen, and received the change.
*   At the third store, he bought an item worth $5$ yen, paid $9$ yen, and did not receive the change.

* * *

### Sample Input 2

```
8
36 49 take
38 73 keep
27 85 take
65 71 take
52 86 keep
48 60 keep
37 98 keep
5 38 keep
```

### Sample Output 2

```
175
```
