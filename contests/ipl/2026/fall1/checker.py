import random
import subprocess
import sys
from pathlib import Path


SOLUTION = Path(__file__).with_name("a.py")


def brute_force(animals):
    n = len(animals)
    answer = 0

    for mask in range(1 << n):
        selected_pigs = [
            i for i, (species, _) in enumerate(animals)
            if mask & (1 << i) and species == "pig"
        ]
        if len(selected_pigs) != 1:
            continue

        pig_influence = animals[selected_pigs[0]][1]
        total = 0
        valid = True

        for i, (species, influence) in enumerate(animals):
            if not mask & (1 << i):
                continue
            if species != "pig" and influence >= pig_influence:
                valid = False
                break
            total += influence

        if valid:
            answer = max(answer, total)

    return answer


def run_solution(test_case):
    result = subprocess.run(
        [sys.executable, str(SOLUTION)],
        input=test_case,
        text=True,
        capture_output=True,
        timeout=2,
    )
    if result.returncode != 0:
        raise RuntimeError(result.stderr.strip() or "solution exited with an error")
    return result.stdout.strip()


def make_case():
    species_names = ["pig", "horse", "cow", "sheep"]
    n = random.randint(1, 10)
    animals = [
        (random.choice(species_names), random.randint(1, 20))
        for _ in range(n)
    ]

    # The problem guarantees at least one pig.
    if not any(species == "pig" for species, _ in animals):
        index = random.randrange(n)
        animals[index] = ("pig", animals[index][1])

    lines = [str(n)]
    lines.extend(f"{species} {influence}" for species, influence in animals)
    return animals, "\n".join(lines) + "\n"


def main():
    random.seed()
    tests = int(sys.argv[1]) if len(sys.argv) > 1 else 1000

    for test_number in range(1, tests + 1):
        animals, test_case = make_case()
        expected = brute_force(animals)
        actual = run_solution(test_case)

        if actual != str(expected):
            print(f"Mismatch on test {test_number}:")
            print(test_case, end="")
            print(f"expected: {expected}")
            print(f"actual:   {actual}")
            return 1

    print(f"All {tests} tests passed.")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
