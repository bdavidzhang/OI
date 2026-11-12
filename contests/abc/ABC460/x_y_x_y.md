<!-- cph-statement -->
# x + y ≡ x + y

https://atcoder.jp/contests/abc460/tasks/abc460_e

Time limit: 2000 ms, memory limit: 1024 MB

Score : $450$ points

### Problem Statement

For positive integers $a$ and $b$, define $\mathrm{concat}(a, b)$ as the integer formed by writing $a$ and $b$ one after another. More formally, $\mathrm{concat}(a, b)$ is defined as follows.

*   Let $A$ and $B$ be the strings formed by writing $a$ and $b$ in decimal, respectively. Let $C$ be the string formed by concatenating $A$ and $B$ in this order. The value of $C$ interpreted as an integer in decimal notation is $\mathrm{concat}(a, b)$.

For example, if $a = 123$ and $b = 45$, then $\mathrm{concat}(a, b) = 12345$.

You are given positive integers $N$ and $M$.  
Find the number, modulo $998244353$, of pairs $(x, y)$ of positive integers not greater than $N$ such that $\mathrm{concat}(x, y) \equiv x + y \pmod{M}$.

You are given $T$ test cases; solve each one.

### Constraints

*   $1 \leq T \leq 10^4$
*   $1 \leq N \leq 10^{18}$
*   $2 \leq M \leq 10^9$
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
N M
```

### Output

Output $T$ lines. The $i$\-th line should contain the answer for the $i$\-th test case.  
For each test case, output the number, modulo $998244353$, of pairs $(x, y)$ satisfying the condition.

* * *

### Sample Input 1

```
4
3 2
123 456
20260530 460
123456789123456789 998244353
```

### Sample Output 1

```
3
0
922576091
422081792
```

For the first test case, three pairs $(x, y)$ satisfy the condition: $(2, 1), (2, 2), (2, 3)$.
