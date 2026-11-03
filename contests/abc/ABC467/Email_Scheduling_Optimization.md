<!-- cph-statement -->
# Email Scheduling Optimization

https://atcoder.jp/contests/abc467/tasks/abc467_f

Time limit: 2000 ms, memory limit: 1024 MB

Score : $525$ points

### Problem Statement

You are given length-$N$ sequences of positive integers $A=(A_1,A_2,\dots,A_N)$ and $B=(B_1,B_2,\dots,B_N)$.  
You are given $Q$ queries.  
Each query is of one of the following two types.

*   `1 i x` : Change $A_i$ to $x$.
*   `2 i x` : Change $B_i$ to $x$.

After processing each query, solve the following problem.

> Takahashi needs to send an email to each of $N$ companies and receive a reply from each of them.  
> Writing the email to send to the $j$\-th company takes $A_j$ minutes, and the reply arrives $B_j$ minutes after it is sent.  
> He starts writing emails at time $0$.  
> He can write the $N$ emails in any order he likes, but he cannot write two or more emails simultaneously.  
> Find the minimum possible time at which he finishes receiving all of the replies.  
> Assume that the time taken to send emails is negligible.

### Constraints

*   $1 \leq N \leq 10^5$
*   $1 \leq Q \leq 10^5$
*   $1 \leq A_j,B_j \leq 10^9$
*   In each query, $1 \leq i \leq N$.
*   In each query, $1 \leq x \leq 10^9$.
*   All input values are integers.

* * *

### Input

The input is given from Standard Input in the following format:

```
N Q  
A_1 A_2 \ldots A_N  
B_1 B_2 \ldots B_N  
\mathrm{query}_1  
\mathrm{query}_2  
\vdots  
\mathrm{query}_Q  
```

For each query $\mathrm{query}_q$, the type of the query ($1$ or $2$), $i$, and $x$ are given in this order, separated by spaces.  
That is, each query is given in one of the following two formats:

```
1 i x  
```

```
2 i x  
```

### Output

Output the answers in a total of $Q$ lines. The $q$\-th line should contain the answer to the problem after processing the $q$\-th query.

* * *

### Sample Input 1

```
3 3
4 6 7
4 6 7
1 2 1
2 3 7
2 3 1
```

### Sample Output 1

```
16
16
13
```

After processing the first query, $A=(4,1,7)$ and $B=(4,6,7)$.  
If Takahashi starts writing the email to send to company $3$ at time $0$, finishes writing it at time $7$, and sends it to company $3$, he receives the reply at time $14$.  
If he starts writing the email to send to company $2$ at time $7$, finishes writing it at time $8$, and sends it to company $2$, he receives the reply at time $14$.  
If he starts writing the email to send to company $1$ at time $8$, finishes writing it at time $12$, and sends it to company $1$, he receives the reply at time $16$.
