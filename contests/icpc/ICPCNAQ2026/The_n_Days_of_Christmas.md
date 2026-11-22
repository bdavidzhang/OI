<!-- cph-statement -->
# The n Days of Christmas

https://naq26.kattis.com/contests/naq26/problems/thendaysofchristmas2

Time limit: 1000 ms, memory limit: 2048 MB

This is a _**SCORED**_ problem. There are ten subgroups of data. The subgroups will be judged independently. Solving all of the data in a subgroup will score $0.1$ of a problem (That’s how it will look on the scoreboard, but it may say $10$ in Kattis’ response). Solving all of the data in all ten subgroups will score $1$ full problem. You may continue to make submissions to try to improve your score.

Time penalty for this problem will be assessed as follows:

*   One point for every minute from the start of the contest to the last submission that increased your score.
    
*   Twenty points for every submission before that last score-increasing submission that did not increase your score, with the exception of compiler errors, which are not assessed penalties.
    
*   No points are assessed if your score never rises above zero
    

Remember the song "The 12 Days of Christmas?"

> _"On the first day of Christmas my true love gave to me, a partridge in a pear tree."_

Great. I wanted an iPhone.

> _"On the second day of Christmas my true love gave to me, two turtle doves, and a partridge in a pear tree."_

OK, now I have four birds: two turtle doves and a partridge today, and a partridge from yesterday. My cats are going crazy.

> _"On the third day of Christmas my true love gave to me, three French hens, two turtle doves, and a partridge in a pear tree."_

What’s with the birds? That’s six more today, so I now have ten of them, and no place to put them (except inside the cats). How long can my true love keep this up?

Given an integer $n$, how many gifts have I received after $n$ days? Since this value may be large, output it modulo $998\, 244\, 353$.

## Input

The single line of input contains an integer $n$, which is the number of days my true love gives me gifts.

There are ten subgroups of data, each with different limits on $n$:

1.  ($1 \le n \le 10$)
    
2.  ($10 < n \le 1\, 000$)
    
3.  ($1\, 000 < n \le 10^5$)
    
4.  ($10^5 < n \le 10^7$)
    
5.  ($10^7 < n \le 10^9$)
    
6.  ($10^9 < n \le 10^{11}$)
    
7.  ($10^{11} < n \le 10^{13}$)
    
8.  ($10^{13} < n \le 10^{15}$)
    
9.  ($10^{15} < n \le 10^{17}$)
    
10.  ($10^{17} < n \le 10^{18}$)
     

## Output

Output a single integer, which is the number of gifts I receive after exactly $n$ days. Because this number may be very large, output it modulo $998\, 244\, 353$.

Sample Input 1

Sample Output 1

```
1
```

```
1
```

Sample Input 2

Sample Output 2

```
2
```

```
4
```

Sample Input 3

Sample Output 3

```
3
```

```
10
```
