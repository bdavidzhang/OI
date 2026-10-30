from math import factorial

def binom(a, b):
    return factorial(a)/factorial(b)/factorial(a-b)

def dnn(a,b):
    ans = 0
    for i in range(min(a,b)+1):
        ans += binom(a,i)*binom(b,i)*2**i
    return ans


def     
        



