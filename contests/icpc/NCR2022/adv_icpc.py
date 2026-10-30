def solve_icpc():
    MOD = 998244353
    
    # Read input
    n, m = map(int, input().split())
    grid = []
    for _ in range(n):
        grid.append(input().strip())
    
    from collections import defaultdict
    
    # DP: process cells in row-major order
    # State: (last m+2 characters as string, has_icpc_flag)
    # We track m+2 chars to check if current position completes ICPC
    
    dp = defaultdict(int)
    dp[("", False)] = 1
    
    letters = ['I', 'C', 'P']
    
    for pos in range(n * m):
        row = pos // m
        col = pos % m
        cell = grid[row][col]
        
        new_dp = defaultdict(int)
        
        for (suffix, has_icpc), count in dp.items():
            # Determine what letters we can place
            options = letters if cell == '?' else [cell]
            
            for letter in options:
                # Add letter to suffix
                new_suffix = suffix + letter
                
                # Keep only last m+2 characters
                if len(new_suffix) > m + 2:
                    new_suffix = new_suffix[-(m+2):]
                
                # Check if current position completes ICPC pattern
                new_has_icpc = has_icpc
                
                if row >= 1 and col >= 1 and len(new_suffix) >= m + 2:
                    # Pattern check: IC on top row, PC on bottom row
                    # Positions relative to current:
                    # [-(m+2)][-(m+1)]  <- top row (row-1, cols col-1 and col)
                    # [  -2  ][  -1  ]  <- bottom row (row, cols col-1 and col)
                    
                    top_left = new_suffix[-(m+2)]
                    top_right = new_suffix[-(m+1)]
                    bottom_left = new_suffix[-2]
                    bottom_right = new_suffix[-1]
                    
                    if (top_left == 'I' and top_right == 'C' and
                        bottom_left == 'P' and bottom_right == 'C'):
                        new_has_icpc = True
                
                new_state = (new_suffix, new_has_icpc)
                new_dp[new_state] = (new_dp[new_state] + count) % MOD
        
        dp = new_dp
    
    # Sum all states where has_icpc is True
    result = 0
    for (suffix, has_icpc), count in dp.items():
        if has_icpc:
            result = (result + count) % MOD
    
    print(result)

solve_icpc()