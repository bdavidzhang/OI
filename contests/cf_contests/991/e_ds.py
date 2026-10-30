import sys

def main():
    data = sys.stdin.read().splitlines()
    t = int(data[0].strip())
    index = 1
    results = []
    for _ in range(t):
        a = data[index].strip()
        b = data[index+1].strip()
        c = data[index+2].strip()
        index += 3
        n = len(a)
        m = len(b)
        total = n + m
        dp = [[-10**9] * (m+1) for _ in range(n+1)]
        dp[0][0] = 0
        
        for i in range(n+1):
            for j in range(m+1):
                current = dp[i][j]
                if i < n:
                    pos = i + j
                    add_val = 1 if a[i] == c[pos] else 0
                    new_val = current + add_val
                    if new_val > dp[i+1][j]:
                        dp[i+1][j] = new_val
                if j < m:
                    pos = i + j
                    add_val = 1 if b[j] == c[pos] else 0
                    new_val = current + add_val
                    if new_val > dp[i][j+1]:
                        dp[i][j+1] = new_val
        
        max_agreement = dp[n][m]
        ans = total - max_agreement
        results.append(str(ans))
    
    sys.stdout.write("\n".join(results))

if __name__ == "__main__":
    main()