def quad(x):
    return x * (x + 1) // 2


def two(n):
    a = n - 2
    c = a // 3
    z = None
    bs = []

    for y in range(max(1, c - 3), min(a, c + 3) + 1):
        if y % 2 == 0:
            continue
        r = a - y
        x = r // 2
        w = r - x
        v = quad(x) + quad(y) + quad(w)
        if z is None or v < z[0]:
            z = (v, x, y, w)

    _, x, y, w = z
    return "0" * x + "1" + "0" * y + "1" + "0" * w, z[0]


def three(n):
    q = (n - 2) // 6
    s = "1" + "0" * (2 * q)
    s += "1" + "0" * (2 * q - 1)
    s += "1" + "0" * (2 * q)
    v = 2 * t(2 * q) + t(2 * q - 1) + 2 * q
    return s, v


def solve(n):
    if n == 1:
        return "1"
    if n == 2:
        return "10"
    if n == 3:
        return "101"

    s, v = two(n)
    if n % 6 == 2:
        q, w = three(n)
        if w < v:
            s = q
    return s


t = int(input())
for _ in range(t):
    print(solve(int(input())))
