<!-- cph-statement -->
# Self-Stopping Shower

https://atcoder.jp/contests/abc480/tasks/abc480_c

Time limit: 2000 ms, memory limit: 1024 MB

Score : $300$ points

### Problem Statement

Takahashi is using a shower at a public bath. This shower has a button. If the button is pressed at time $t$, hot water comes out for $K$ seconds, from time $t$ to time $t+K$. Even if the button is pressed again while hot water is coming out, hot water comes out for $K$ seconds from the time the button was last pressed.

There are $N$ Aokis, each of whom presses the button once. The $i$\-th Aoki presses the button at time $A_i$.

Find the minimum number of times Takahashi needs to press the button so that hot water is always coming out from time $0$ to time $T$. Here, hot water is considered to be coming out both at the moment the button is pressed and at the moment exactly $K$ seconds after the last press.

### Constraints

*   $1 \leq N \leq 2 \times 10^5$
*   $1 \leq K \leq 10^9$
*   $1 \leq T \leq 10^9$
*   $0 \leq A_i \leq 10^9$
*   All input values are integers.

* * *

### Input

The input is given from Standard Input in the following format:

```
N K T  
A_1 A_2 \ldots A_N  
```

### Output

Print the answer in a single line.

* * *

### Sample Input 1

```
3 4 20
6 7 12
```

### Sample Output 1

```
4
```

If Takahashi presses the button at times $0,2,10,16$, hot water is always coming out from time $0$ to time $20$.  
If he presses the button $3$ times or fewer, it is impossible to keep hot water always coming out, so the answer is $4$.

* * *

### Sample Input 2

```
9 37 480
12 123 132 213 231 312 321 500 1000
```

### Sample Output 2

```
11
```
