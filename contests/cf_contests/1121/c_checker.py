import itertools
import random
import subprocess
import sys
from pathlib import Path


MOD = 998244353


def brute_force(ratings):
    root = max(ratings)
    children = [rating for rating in ratings if rating != root]
    parent_choices = [
        [parent for parent in ratings if parent > child]
        for child in children
    ]

    total = 0
    for parents in itertools.product(*parent_choices):
        total += sum(parent - child for child, parent in zip(children, parents))
    return total % MOD


def generate_cases(test_count, max_size):
    cases = []
    for _ in range(test_count):
        size = random.randint(1, max_size)
        cases.append(random.sample(range(1, 100), size))
    return cases


def format_input(cases):
    lines = [str(len(cases))]
    for ratings in cases:
        lines.append(str(len(ratings)))
        lines.append(" ".join(map(str, ratings)))
    return "\n".join(lines) + "\n"


def main():
    test_count = int(sys.argv[1]) if len(sys.argv) > 1 else 300
    random.seed(1)
    cases = generate_cases(test_count, 7)
    input_data = format_input(cases)
    expected = [str(brute_force(ratings)) for ratings in cases]

    solution_path = Path(__file__).with_name("c.py")
    result = subprocess.run(
        [sys.executable, str(solution_path)],
        input=input_data,
        text=True,
        capture_output=True,
    )
    if result.returncode != 0:
        print("c.py crashed:")
        print(result.stderr, end="")
        raise SystemExit(1)

    actual = result.stdout.split()
    if actual != expected:
        for index, (got, want) in enumerate(zip(actual, expected)):
            if got != want:
                print(f"Mismatch in case {index + 1}: got {got}, expected {want}")
                print("Input:")
                print(format_input([cases[index]]), end="")
                raise SystemExit(1)
        print(f"Wrong number of answers: got {len(actual)}, expected {len(expected)}")
        raise SystemExit(1)

    print(f"Passed {len(cases)} brute-force cases")


if __name__ == "__main__":
    main()