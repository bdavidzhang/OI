"""Randomized stress checker for a.py."""

import argparse
import random
import subprocess
import sys
from pathlib import Path


def solve_case(values):
    """Try every non-empty subset of indices as the reversed subsequence."""
    target = sorted(values)
    size = len(values)

    for mask in range(1, 1 << size):
        indices = [index for index in range(size) if mask & (1 << index)]
        candidate = values[:]
        selected = [candidate[index] for index in indices]
        for index, value in zip(indices, reversed(selected)):
            candidate[index] = value
        if candidate == target:
            return "YES"

    return "NO"


def generate_cases(test_count, max_size):
    cases = []
    for _ in range(test_count):
        size = random.randint(1, max_size)
        values = list(range(1, size + 1))
        random.shuffle(values)
        cases.append(values)
    return cases


def format_input(cases):
    lines = [str(len(cases))]
    for values in cases:
        lines.append(str(len(values)))
        lines.append(" ".join(map(str, values)))
    return "\n".join(lines) + "\n"


def main():
    parser = argparse.ArgumentParser(description="Stress-test a.py with random cases")
    parser.add_argument("-t", "--tests", type=int, default=1000)
    parser.add_argument("--max-size", type=int, default=8)
    parser.add_argument("--seed", type=int, default=None)
    args = parser.parse_args()

    if args.seed is not None:
        random.seed(args.seed)

    cases = generate_cases(args.tests, args.max_size)
    input_data = format_input(cases)
    expected = "\n".join(solve_case(values) for values in cases).split()

    solution_path = Path(__file__).with_name("a.py")
    result = subprocess.run(
        [sys.executable, str(solution_path)],
        input=input_data,
        text=True,
        capture_output=True,
    )
    if result.returncode != 0:
        print("a.py crashed:")
        print(result.stderr, end="")
        print("\nInput:")
        print(input_data, end="")
        raise SystemExit(1)

    actual = result.stdout.split()
    if actual != expected:
        mismatch_index = None
        for index, (got, want) in enumerate(zip(actual, expected)):
            if got != want:
                print(f"Mismatch in case {index + 1}: got {got}, expected {want}")
                mismatch_index = index
                break
        else:
            print("a.py produced the wrong number of answers")
            mismatch_index = min(len(actual), len(expected))
        if mismatch_index < len(cases):
            print("\nMinimal failing input:")
            print(format_input([cases[mismatch_index]]), end="")
        raise SystemExit(1)

    print(f"Passed {len(cases)} random test cases")


if __name__ == "__main__":
    main()