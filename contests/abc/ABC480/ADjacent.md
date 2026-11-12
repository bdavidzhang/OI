<!-- cph-statement -->
# ADjacent

https://atcoder.jp/contests/abc480/tasks/abc480_a

Time limit: 2000 ms, memory limit: 1024 MB

Score : $100$ points

### Problem Statement

There is a grid with $2$ rows and $2$ columns.

Each cell of the grid contains exactly one of `A`, `B`, `C`, and `D`, and the characters written in the $4$ cells are distinct. The cell at the $i$\-th row from the top and the $j$\-th column from the left contains $S_{i,j}$.

If the cell containing `A` and the cell containing `D` are adjacent, that is, they share an edge, print `Yes`; otherwise, print `No`.

### Constraints

*   $S_{i,j}$ is one of `A`, `B`, `C`, and `D`.
*   If $(i_1,j_1)\neq (i_2,j_2)$, then $S_{i_1,j_1}$ and $S_{i_2,j_2}$ are distinct.

* * *

### Input

The input is given from Standard Input in the following format:

```
S_{1,1}S_{1,2}  
S_{2,1}S_{2,2}   
```

### Output

Print the answer in a single line.

* * *

### Sample Input 1

```
AB
DC
```

### Sample Output 1

```
Yes
```

`A` is written in the cell at the $1$\-st row from the top and the $1$\-st column from the left.  
`D` is written in the cell at the $2$\-nd row from the top and the $1$\-st column from the left.  
These $2$ cells share an edge, so they are adjacent.

* * *

### Sample Input 2

```
AB
CD
```

### Sample Output 2

```
No
```

* * *

### Sample Input 3

```
BD
CA
```

### Sample Output 3

```
Yes
```
