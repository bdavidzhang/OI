import sys

def solve():
    input = sys.stdin.readline
    
    n, q = map(int, input().split())
    a = list(map(int, input().split()))

    min_end = [n] * (n + 1)

    for i in range(n - 1, -1, -1):
        min_end[i] = min_end[i + 1]
        if i + 2 < n:
            if a[i] > a[i+1] > a[i+2]:
                min_end[i] = min(min_end[i], i + 2)
        if i + 3 < n:
            if a[i] > a[i+1] > a[i+3]:
                min_end[i] = min(min_end[i], i + 3)
            if a[i] > a[i+2] > a[i+3]:
                min_end[i] = min(min_end[i], i + 3)
    
    for _ in range(q):
        l, r = map(int, input().split())
        l_idx, r_idx = l - 1, r - 1
        
        if r - l + 1 < 3:
            sys.stdout.write("YES\n")
            continue

        if min_end[l_idx] <= r_idx:
            sys.stdout.write("NO\n")
        else:
            sys.stdout.write("YES\n")

def main():
    num_test_cases = int(sys.stdin.readline())
    for _ in range(num_test_cases):
        solve()

if __name__ == "__main__":
    main()