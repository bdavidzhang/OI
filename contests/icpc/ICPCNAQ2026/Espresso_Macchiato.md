<!-- cph-statement -->
# Espresso Macchiato

https://naq26.kattis.com/contests/naq26/problems/espressomacchiato

Time limit: 1000 ms, memory limit: 2048 MB

Tommy likes two things: city planning and espresso macchiatos. His days are packed, he works around the clock, and he has barely a minute to stop and talk – but a man has his priorities, and his coffee is very important to him. So, when he is handed the job of planning a whole new city, he sees his chance: to guarantee himself exactly one macchiato on the way to work, every single morning, no stress.

The city is an $n \times n$ grid. Tommy’s home sits in the top-left corner and his workplace in the bottom-right. He is forever in a rush, so on the walk from home to work he only ever moves right and down.

He wants to design the city so that both of the following hold:

*   Each square in the grid has either no coffee shop or exactly one coffee shop. Tommy’s home and workplace cannot have coffee shops.
    
*   No matter how Tommy walks in the grid, his path takes him through exactly one square that has a coffee shop.
    

One macchiato every morning – never none, because he needs it, and never two, because who has the time? Help him design the city to fit his constraints!

## Input

The first line of input contains a single integer $t$ $(1 \le t \le 49)$, which is the number of test cases.

The descriptions of $t$ test cases follow. Each test case consists of a single line with a single integer $n$ $(2 \le n \le 50)$ which is the size of the city Tommy is planning.

## Output

For each test case, output an $n \times n$ grid. Each character is either a . to indicate a square without a coffee shop or a C to indicate a square with a coffee shop.

If there are multiple city plans that are valid, any will be accepted. It can be proven that it is always possible to construct a valid city plan.

Sample Input 1

Sample Output 1

```
2
6
7
```

```
.....C
....C.
...C..
..C...
.C....
C.....
.......
.......
.......
.......
......C
.....C.
....C..
```
