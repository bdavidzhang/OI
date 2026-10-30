import itertools
import subprocess
import sys

MOD = 10**9 + 7


def mex(values):
    values = set(values)
    answer = 0
    while answer in values:
        answer += 1
    return answer


def array_for_subset(subset, n):
    return tuple(mex(x // k for x in subset) for k in range(1, n + 1))


def brute_force_count(expected, n):
    count = 0
    for mask in range(1 << n):
        subset = [x for x in range(n) if mask & (1 << x)]
        if array_for_subset(subset, n) == expected:
            count += 1
    return count


def main():
    cases = []
    for n in range(1, 9):
        seen = set()
        for mask in range(1 << n):
            subset = [x for x in range(n) if mask & (1 << x)]
            expected = array_for_subset(subset, n)
            if expected not in seen:
                seen.add(expected)
                cases.append((n, expected, brute_force_count(expected, n)))

    input_data = str(len(cases)) + "\n"
    input_data += "\n".join(
        f"{n}\n{' '.join(map(str, expected))}" for n, expected, _ in cases
    ) + "\n"
    result = subprocess.run(
        [sys.executable, "c2.py"],
        input=input_data,
        text=True,
        capture_output=True,
        check=False,
    )
    if result.returncode != 0:
        print(result.stderr, file=sys.stderr)
        raise SystemExit(result.returncode)

    answers = result.stdout.split()
    if len(answers) != len(cases):
        raise AssertionError("wrong number of answers")
    for index, ((n, expected, correct), answer) in enumerate(zip(cases, answers)):
        if int(answer) != correct % MOD:
            raise AssertionError(
                f"case {index}: n={n}, a={expected}, expected {correct}, got {answer}"
            )
    print(f"c2.py passed {len(cases)} brute-force cases for n=1..8")


if __name__ == "__main__":
    main()
