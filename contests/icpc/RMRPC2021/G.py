m = int(input())
n = int(input())

def gcd(a,b):
    while(b != 0):
        temp = b
        b =a % b
        a = temp
    return a

def isprime(a):
    i = 2
    while(i*i <= a):
        if(a % i == 0):
            return False
    return True

def issquarediv(a):
    i = 2
    while(i*i <= a):
        if(a % (i*i) == 0):
            return False
    return True

if(isprime(m) and isprime(n)):
    if(gcd(m,n) == 0):
        print("full credit")
    else:
        print("no credit")
else:
    if(gcd(a,b) == 1 and issquarediv(a) == False and issquarediv(b) == False):
        print("partial credit")
    else:
        print("no credit")
   

        

