<!-- cph-statement -->
# Invalid Vote

https://atcoder.jp/contests/abc480/tasks/abc480_b

Time limit: 2000 ms, memory limit: 1024 MB

Score : $200$ points

### Problem Statement

$N$ candidates $1,2,\dots,N$ are running in an election. The name of each candidate consists of lowercase English letters, and the names are distinct. The name of candidate $i$ is $S_i$.

$M$ ballots $1,2,\dots,M$ were cast, and ballot $j$ has a string $T_j$ consisting of lowercase English letters written on it.

If there is a candidate whose name exactly matches $T_j$, that candidate receives $1$ vote. Otherwise, if there is exactly one candidate whose name can be obtained by changing $1$ character of $T_j$, that candidate receives $1$ vote. Otherwise, the ballot is invalid.

For each $i=1,2,\dots,N$, find how many votes candidate $i$ receives.

### Constraints

*   $1 \leq N \leq 100$
*   $1 \leq M \leq 100$
*   $1 \leq |S_i| \leq 10$
*   $S_i \neq S_j$ if $i \neq j$.
*   $1 \leq |T_j| \leq 10$
*   $S_i$ and $T_j$ are strings consisting of lowercase English letters.
*   $N$ and $M$ are integers.

* * *

### Input

The input is given from Standard Input in the following format:

```
N M  
S_1  
S_2  
\vdots  
S_N  
T_1  
T_2  
\vdots  
T_M  
```

### Output

Print $N$ lines in total.  
The $i$\-th line should contain the number of votes candidate $i$ receives.

* * *

### Sample Input 1

```
5 8
takahashi
aoki
sato
kato
kano
aoki
takanashi
sano
atcoder
chokudai
kato
aoki
yato
```

### Sample Output 1

```
1
2
0
1
0
```

There are $5$ candidates: `takahashi`, `aoki`, `sato`, `kato`, and `kano`.  
Ballot $1$ has `aoki` written on it.  
Candidate $2$ receives $1$ vote.

Ballot $2$ has `takanashi` written on it.  
Changing the $5$\-th character from `n` to `h` makes it match the name of candidate $1$, and there is no other such candidate, so candidate $1$ receives $1$ vote.

Ballot $3$ has `sano` written on it.  
Changing the $3$\-rd character from `n` to `t` makes it match the name of candidate $3$, and changing the $1$\-st character from `s` to `k` makes it match the name of candidate $5$, so this ballot is invalid.

* * *

### Sample Input 2

```
2 5
a
b
a
b
c
a
aa
```

### Sample Output 2

```
2
1
```
