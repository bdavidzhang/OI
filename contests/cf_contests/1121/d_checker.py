import itertools
import subprocess
import sys
from pathlib import Path


def cost(s):
    n = len(s)
    z = 0
    for l in range(n):
        v = 0
        for r in range(l, n):
            v = (2 * v + int(s[r])) % 3
            z += v == 0
    return z


def best(n):
    z = None
    for k in range(4):
        for p in itertools.combinations(range(n), k):
            q = set(p)
            s = "".join("1" if i in q else "0" for i in range(n))
            z = cost(s) if z is None else min(z, cost(s))
    return z


def main():
    ns = list(range(1, 31))
    data = str(len(ns)) + "\n" + "\n".join(map(str, ns)) + "\n"
    result = subprocess.run(
        [sys.executable, str(Path(__file__).with_name("d.py"))],
        input=data,
        text=True,
        capture_output=True,
    )

    if result.returncode != 0:
        print("d.py crashed:")
        print(result.stderr, end="")
        raise SystemExit(1)

    actual = result.stdout.split()
    if len(actual) != len(ns):
        print(f"Expected {len(ns)} answers, got {len(actual)}")
        raise SystemExit(1)

    for n, s in zip(ns, actual):
        if len(s) != n or any(c not in "01" for c in s) or s.count("1") > 3:
            print(f"Invalid answer for n={n}: {s!r}")
            raise SystemExit(1)

        got = cost(s)
        want = best(n)
        if got != want:
            print(f"Wrong answer for n={n}: {s}, cost={got}, optimum={want}")
            raise SystemExit(1)

    print(f"Passed exact checks for n=1..{ns[-1]}")


if __name__ == "__main__":
    main()