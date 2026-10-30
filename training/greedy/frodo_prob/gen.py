import random

def random_tree(n, k=None):
    edges = []
    for i in range(2, n + 1):
        parent = random.randint(1, i - 1)
        edges.append((parent, i))
    if k is None:
        k = random.randint(0, n - 1)
    print(f"{n} {k}")
    for u, v in edges:
        print(f"{u} {v}")

if __name__ == "__main__":
    # n = 5
    n = random.randint(5, 10)  # small for brute-force
    random_tree(n)
