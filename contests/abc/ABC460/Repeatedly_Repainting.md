<!-- cph-statement -->
# Repeatedly Repainting

https://atcoder.jp/contests/abc460/tasks/abc460_d

Time limit: 2000 ms, memory limit: 1024 MB

Score : $425$ points

### Problem Statement

There is a grid with $H$ rows and $W$ columns. The cell at the $i$\-th row from the top and the $j$\-th column from the left is called cell $(i, j)$.

Every cell is colored white or black. The grid is described by $H$ strings $S_1, S_2, \ldots, S_H$, each of length $W$. If the $j$\-th character of $S_i$ is `.`, cell $(i, j)$ is white; if the $j$\-th character of $S_i$ is `#`, cell $(i, j)$ is black.

You perform the following operation $10^{100}$ times.

*   Simultaneously apply the following rules to all cells.
    *   A cell that is white before the operation becomes black if and only if there exists at least one black cell adjacent to it. Here, cells $(x, y)$ and $(x', y')$ are adjacent if and only if one of them is within the $8$\-neighborhood of the other, that is, $\max(|x-x'|, |y-y'|) = 1$.
    *   A cell that is black before the operation becomes white.

Find the color of each cell after the operations.

### Constraints

*   $1 \leq H \times W \leq 10^6$
*   $H$ and $W$ are positive integers.
*   $S_i$ is a string of length $W$ consisting of `.` and `#`.

* * *

### Input

The input is given from Standard Input in the following format:

```
H W
S_1
S_2
\vdots
S_H
```

### Output

Output $H$ lines.

Output one string of length $W$ consisting of `.` and `#` per line.

The $j$\-th character of the $i$\-th line should be `.` if cell $(i, j)$ is white after $10^{100}$ operations, and `#` if it is black.

* * *

### Sample Input 1

```
3 4
#.#.
.#..
#...
```

### Sample Output 1

```
#.#.
.#..
#..#
```

Initially, the grid is as follows.

![](https://img.atcoder.jp/abc460/627ea6dbe86e256ffed0acb1673bbc24.png)

After one operation, the grid is as follows.

![](https://img.atcoder.jp/abc460/e38dfa210531a6f57653265405278d67.png)

After $10^{100}$ operations, the grid is as follows.

![](https://img.atcoder.jp/abc460/6ff5ae88f660cb5847497674a81f8cdd.png)

* * *

### Sample Input 2

```
3 3
###
###
###
```

### Sample Output 2

```
...
...
...
```

* * *

### Sample Input 3

```
5 7
.#.....
.......
..#....
.......
....#..
```

### Sample Output 3

```
.#.##.#
....#..
#.#.###
#.....#
###.#.#
```
