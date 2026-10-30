def solve():
    n = int(input())
    a = list(map(int, input().split()))

    min_total_cost = float('inf')
    i = 0
    while i < n:
        current_block_start_idx_0based = i
        current_value = a[i]
        
        j = i
        while j < n and a[j] == current_value:
            j += 1
        
        p_1based = current_block_start_idx_0based + 1
        q_1based = j 
        
        cost_for_this_block = 0
        if p_1based > 1:
            cost_for_this_block += (p_1based - 1) * current_value
        
        if q_1based < n: 
            cost_for_this_block += (n - q_1based) * current_value
            
        min_total_cost = min(min_total_cost, cost_for_this_block)
        
        i = j 

    print(min_total_cost)

t = int(input())
for _ in range(t):
    solve()