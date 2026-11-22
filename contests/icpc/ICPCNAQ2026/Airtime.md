<!-- cph-statement -->
# Airtime

https://naq26.kattis.com/contests/naq26/problems/airtime

Time limit: 2000 ms, memory limit: 2048 MB

Fred loves roller coasters! He particularly loves airtime – that’s where the coaster goes over an element that causes riders to float out of their seats!

Fred has been doing a lot of internet research, and he’s found a lot of data on a lot of roller coasters. He has collected many altitude profiles, which give the height of the track at many points along the course, in order. These measurements have been taken from one of each coaster’s trains at regular one-second intervals.

Fred knows that he’ll get some airtime if the track forms an arcing shape. Formally, given three consecutive altitude measurements $a_i$, $a_{i+1}$ and $a_{i+2}$ at times $t_i$, $t_{i+1}$ and $t_{i+2}$, he’ll get a second of airtime iff the slope from $(t_i,a_i)$ to $(t_{i+1},a_{i+1})$ is strictly greater than the slope from $(t_{i+1},a_{i+1})$ to $(t_{i+2},a_{i+2})$

![\includegraphics[width=0.58\textwidth ]{airtime-illustration}](https://naq26.kattis.com/problems/airtime/file/statement/en/img-0001.png)

Given the altitude profile of a roller coaster, determine how many seconds of airtime Fred can experience.

## Input

The first line of input contains an integer $n$ ($3 \le n \le 10^5$), which is the number of altitude measurements to follow.

Each of the next $n$ lines contains an integer $a$ ($0 \le a \le 10^9$). This is the sequence of altitude measurements, in inches. They are given in order, one per second.

## Output

Output a single integer, which is the total number of seconds of airtime Fred can experience on this roller coaster.

Sample Input 1

Sample Output 1

```
13
1
2
3
3
4
5
6
5
4
4
4
3
2
```

```
3
```

Sample Input 2

Sample Output 2

```
7
1
3
8
15
25
40
60
```

```
0
```
