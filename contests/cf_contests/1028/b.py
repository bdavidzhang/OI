t = int(input().strip())
MOD = 998244353

for _ in range(t):
    n = int(input().strip())
    p = list(map(int, input().split()))
    q = list(map(int, input().split()))
    
    # Collect distinct exponents from p and q
    distinct_exponents = set(p) | set(q)
    # Precompute 2^exp mod MOD for each distinct exponent
    power_dict = {}
    for exp in distinct_exponents:
        power_dict[exp] = pow(2, exp, MOD)
    
    # Build maxp and maxq arrays
    maxp = []
    maxq = []
    largep = -10**18
    largeq = -10**18
    for i in range(n):
        if p[i] > largep:
            largep = p[i]
            maxp.append((p[i], i))
        else:
            maxp.append(maxp[-1])
        if q[i] > largeq:
            largeq = q[i]
            maxq.append((q[i], i))
        else:
            maxq.append(maxq[-1])
    
    res = []
    for i in range(n):
        valp, idxp = maxp[i]
        valq, idxq = maxq[i]
        if valp < valq:
            term1 = power_dict[valq]
            term2 = power_dict[p[i - idxq]]
            total = (term1 + term2) % MOD
            res.append(total)
        elif valp > valq:
            term1 = power_dict[valp]
            term2 = power_dict[q[i - idxp]]
            total = (term1 + term2) % MOD
            res.append(total)
        else:
            term1 = power_dict[valp]
            exp2 = max(q[i - idxp], p[i - idxq])
            term2 = power_dict[exp2]
            total = (term1 + term2) % MOD
            res.append(total)
    
    # Format output
    print(" ".join(map(str, res)))