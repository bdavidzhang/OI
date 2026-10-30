import itertools
import subprocess
import sys


def minimum_count(matrix, n):
    minima = {min(row) for row in matrix}
    minima.update(min(matrix[row][column] for row in range(n)) for column in range(n))
    return len(minima)


def brute_force_possible(n):
    possible = set()
    values = range(1, n * n + 1)
    for permutation in itertools.permutations(values):
        matrix = [permutation[row * n:(row + 1) * n] for row in range(n)]
        possible.add(minimum_count(matrix, n))
    return possible


def possible_for(n, k, brute_force_results):
    if n <= 3:
        return k in brute_force_results[n]
    return n <= k < 2 * n


def validate_output(output, cases, possible):
    lines = output.splitlines()
    line_index = 0

    for case_index, (n, k) in enumerate(cases):
        if line_index >= len(lines):
            raise AssertionError(f"case {case_index}: missing output")

        line = lines[line_index].strip()
        line_index += 1
        if line == "-1":
            if possible_for(n, k, possible):
                raise AssertionError(f"case {case_index}: reported -1 for possible k={k}")
            continue

        first_row = line.split()
        if len(first_row) != n:
            raise AssertionError(f"case {case_index}: expected {n} integers per row")

        rows = [first_row]
        for _ in range(n - 1):
            if line_index >= len(lines):
                raise AssertionError(f"case {case_index}: incomplete matrix")
            rows.append(lines[line_index].split())
            line_index += 1

        if any(len(row) != n for row in rows):
            raise AssertionError(f"case {case_index}: expected an {n}x{n} matrix")

        try:
            matrix = [[int(value) for value in row] for row in rows]
        except ValueError as error:
            raise AssertionError(f"case {case_index}: matrix contains non-integers") from error

        if sorted(value for row in matrix for value in row) != list(range(1, n * n + 1)):
            raise AssertionError(f"case {case_index}: matrix is not a permutation of 1..n^2")

        actual = minimum_count(matrix, n)
        if actual != k:
            raise AssertionError(
                f"case {case_index}: expected |f(A)|={k}, got {actual}"
            )

    if any(line.strip() for line in lines[line_index:]):
        raise AssertionError("extra output after the final case")


def main():
    cases = [(n, k) for n in range(1, 10) for k in range(0, 2 * n + 1)]
    possible = {n: brute_force_possible(n) for n in range(1, 4)}
    input_data = str(len(cases)) + "\n" + "\n".join(f"{n} {k}" for n, k in cases) + "\n"

    result = subprocess.run(
        [sys.executable, "b.py"],
        input=input_data,
        text=True,
        capture_output=True,
        check=False,
    )
    if result.returncode != 0:
        print(result.stderr, file=sys.stderr)
        raise SystemExit(result.returncode)

    validate_output(result.stdout, cases, possible)
    print("b.py passed exhaustive checks for n=1,2,3")


if __name__ == "__main__":
    main()
