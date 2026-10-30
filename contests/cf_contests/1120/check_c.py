import itertools
import subprocess
import sys


def mex(values):
    values = set(values)
    answer = 0
    while answer in values:
        answer += 1
    return answer


def make_array(subset, n):
    return [mex(x // denominator for x in subset) for denominator in range(1, n + 1)]


def validate_output(output, cases):
    tokens = output.split()
    position = 0

    for case_index, (n, expected) in enumerate(cases):
        if position >= len(tokens):
            raise AssertionError(f"case {case_index}: missing answer size")

        try:
            size = int(tokens[position])
        except ValueError as error:
            raise AssertionError(f"case {case_index}: answer size is not an integer") from error
        position += 1

        if not 0 <= size <= n:
            raise AssertionError(f"case {case_index}: invalid answer size {size}")
        if position + size > len(tokens):
            raise AssertionError(f"case {case_index}: incomplete subset")

        try:
            subset = [int(token) for token in tokens[position:position + size]]
        except ValueError as error:
            raise AssertionError(f"case {case_index}: subset contains non-integers") from error
        position += size

        if len(set(subset)) != size or any(value < 0 or value >= n for value in subset):
            raise AssertionError(f"case {case_index}: answer is not a subset of [0, n-1]")

        actual = make_array(subset, n)
        if actual != expected:
            raise AssertionError(
                f"case {case_index}: expected {expected}, got {actual} from {subset}"
            )

    if position != len(tokens):
        raise AssertionError("extra output after the final case")


def main():
    cases_by_key = {}
    for n in range(1, 9):
        for mask in range(1 << n):
            subset = [value for value in range(n) if mask & (1 << value)]
            expected = tuple(make_array(subset, n))
            cases_by_key[(n, expected)] = (n, list(expected))

    cases = list(cases_by_key.values())
    input_data = str(len(cases)) + "\n"
    input_data += "\n".join(
        f"{n}\n{' '.join(map(str, expected))}" for n, expected in cases
    ) + "\n"

    result = subprocess.run(
        [sys.executable, "c.py"],
        input=input_data,
        text=True,
        capture_output=True,
        check=False,
    )
    if result.returncode != 0:
        print(result.stderr, file=sys.stderr)
        raise SystemExit(result.returncode)

    validate_output(result.stdout, cases)
    print(f"c.py passed {len(cases)} brute-force cases for n=1..8")


if __name__ == "__main__":
    main()
