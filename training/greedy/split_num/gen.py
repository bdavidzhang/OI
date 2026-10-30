import random

def gen():
    n = random.randint(1, 20)
    # print(n)
    # arr = [random.randint(0, 100) for _ in range(n)]
    # print(*arr)
    k = random.randint(1,n)
    print(f"{n} {k}")

if __name__ == "__main__":
    gen()
