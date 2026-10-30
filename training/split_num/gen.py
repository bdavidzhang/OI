import random

def gen():
    n = random.randint(1, 10)
    print(n)
    arr = [random.randint(0, 100) for _ in range(n)]
    print(*arr)

if __name__ == "__main__":
    gen()
