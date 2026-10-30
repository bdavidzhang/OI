from math import *
A,B = map(int,input().split())

def sqfree(x):
    y = 2
    while y * y <= x:
        if x % (y*y) == 0: return False
        y += 1
    return True

def isp(x):
    y = 2
    while y * y <= x:
        if x % y == 0: return False
        y += 1
    return True


if isp(A) and isp(B) and A != B: print("full credit")
elif sqfree(A) and sqfree(B) and gcd(A,B) == 1: print("partial credit")
else: print("no credit")
