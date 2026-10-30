<!-- cph-statement -->
# coltype

https://open.kattis.com/problems/coltype

Time limit: 1000 ms, memory limit: 64 MB

The _**Collatz function**_, C(_n_), on positive integers is:

_n_/2 if _n_ is even and 3_n_+1 if _n_ is odd

The _**Collatz sequence**_, CS(_n_), of a positive integer, _n_, is the sequence

CS(_n_) = n, C(_n_), C(C(_n_)), C(C(C(_n_))), …

For example, CS(12) = 12, 6, 3, 10, 5, 16, 8, 4, 2, 1, 4, 2, 1, …

The _**Collatz Conjecture**_ (also known as the _3n+1 problem_) is that CS(_n_) for every positive integer _n_ eventually ends repeating the sequence 4, 2, 1. To date, the status of this conjecture is still unknown. No proof has been given and no counterexample has been found up to very large values.

Prof. Fumblemore wants to study the problem using _Collatz sequence types_. The _Collatz sequence type_ (CST) of an integer _n_, CST(_n_) is a sequence of letters E and O (for even and odd) which describe the parity of the values in CS(_n_) up to but not including the first power of 2. So,

CST(12) = EEOEO

Note that

CS(908) = 908, 454, 227, 682, 341, 1024, 512, 256, 128, 64, 32, 16, 8, 4, 3, 2, …

so 12 and 908 have the same CST.

Prof. Fumblemore needs a program which allows him to enter a sequence of E’s and O’s and returns the **smallest** integer _n_ for which the given sequence is CST(_n_).

Notes:

*   E’s are even numbers which are not powers of 2,
    
*   O’s are odd numbers greater than 1.
    
*   The last letter in a sequence must be an O (if C(_n_) is a power of 2, so is _n_)
    
*   There can not be two O’s in succession (C(odd) = even)
    
*   Since, Prof. Fumblemore does not type well, you must check that the input sequence is valid before attempting to find _n_. That is, the sequence contains only E’s and O’s, ends in O and no two O’s are adjacent.
    

## Input

Input consists of one line containing a string of up to 50 letters composed of E’s and O’s.

## Output

There is one line of output that consists of the string INVALID if the input line is invalid, or a single decimal integer, _n_, such that _n_ is the _smallest_ integer for which CST(_n_) is the input sequence. Input will be chosen such that $n \le 2^{47}$.

Sample Input 1

Sample Output 1

```
EEOEO
```

```
12
```

Sample Input 2

Sample Output 2

```
EEOOEO
```

```
INVALID
```
