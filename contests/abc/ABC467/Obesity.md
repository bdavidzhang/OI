<!-- cph-statement -->
# Obesity

https://atcoder.jp/contests/abc467/tasks/abc467_a

Time limit: 2000 ms, memory limit: 1024 MB

Score : $100$ points

### Problem Statement

The value calculated by the following formula is called $\mathrm{BMI}[\mathrm{kg}/\mathrm{m}^2]$. ($\div$ denotes division.)

*   $\text{Weight}[\mathrm{kg}] \div \text{Height}[\mathrm{m}] \div \text{Height}[\mathrm{m}]$

In Japan, a person whose $\mathrm{BMI}$ is $25 \; \mathrm{kg}/\mathrm{m}^2$ or more is considered obese.  
Determine whether a person with height $H[\mathrm{cm}]$ and weight $W[\mathrm{kg}]$ is considered obese in Japan.

### Constraints

*   $1 \leq H \leq 300$
*   $1 \leq W \leq 300$
*   All input values are integers.

* * *

### Input

The input is given from Standard Input in the following format:

```
H W  
```

### Output

Output `Yes` on one line if a person with height $H[\mathrm{cm}]$ and weight $W[\mathrm{kg}]$ is considered obese in Japan, and `No` otherwise.

* * *

### Sample Input 1

```
180 60
```

### Sample Output 1

```
No
```

Since the height is $180 \; \mathrm{cm}=1.8 \; \mathrm{m}$, the $\mathrm{BMI}$ is $60 \; \mathrm{kg} \div 1.8 \; \mathrm{m} \div 1.8 \; \mathrm{m}=18.5\dots \; \mathrm{kg}/\mathrm{m}^2$, so this person is not considered obese.

* * *

### Sample Input 2

```
182 188
```

### Sample Output 2

```
Yes
```

* * *

### Sample Input 3

```
180 81
```

### Sample Output 3

```
Yes
```
