<!-- cph-statement -->
# Fairytale

https://naq26.kattis.com/contests/naq26/problems/fairytale

Time limit: 1000 ms, memory limit: 2048 MB

Alexander is writing his fairytale – the one he can’t quite let go of, about the girl he loved. He means to carry the whole of it as music on his violin, the way only he can, having composed it, sung it, and bowed it all himself.

A violin has four strings, and for Alexander each string is capable of producing $10$ unique pitches. Specifically, the first string can produce pitches $1$ through $10$, the second pitches $11$ through $20$, the third $21$ through $30$, and the fourth $31$ through $40$.

He has finished the violin accompaniment, and before he plays it through he wants to know how far across the instrument the melody actually roams – how many of the four strings his fairytale calls for. Help him!

## Input

The first line of input contains a single integer $t$ $(1 \le t \le 50)$, which is the number of test cases.

The descriptions of $t$ test cases follow. Each test case starts with a line containing a single integer $n$ ($1 \le n \le 50$), which is the number of notes in the accompaniment.

The next line contains $n$ integers $p$ ($1 \le p \le 40$), the pitches of the $n$ notes in the accompaniment.

## Output

For each test case, output a single integer, which is the number of strings that will be used, one per line.

Sample Input 1

Sample Output 1

```
4
3
1 5 10
4
11 20 31 40
5
7 10 11 20 29
6
1 11 21 30 31 40
```

```
1
2
3
4
```
