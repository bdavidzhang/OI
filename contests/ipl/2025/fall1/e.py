def is_prime(n: int) -> bool:
    if n < 2:
        return False
    if n % 2 == 0:
        return n == 2
    i = 3
    while i * i <= n:
        if n % i == 0:
            return False
        i += 2
    return True

tt = int(input())
for _ in range(tt):
    a, b = map(int, input().split())
    if a - b == 1 and is_prime(a + b):
        print("YES")
    else:
        print("NO")
