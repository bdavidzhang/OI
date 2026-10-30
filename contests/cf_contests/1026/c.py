import sys

def solve():
    n = int(sys.stdin.readline())
    d_input = list(map(int, sys.stdin.readline().split())) # 0-indexed, d_input[k] is for step k to k+1
    
    obstacles = [] # obstacles[k] are (l,r) constraints for h[k+1]
    for _ in range(n):
        obstacles.append(list(map(int, sys.stdin.readline().split())))

    min_h = [0] * (n + 1) # min_h[k] is min height at step k
    max_h = [0] * (n + 1) # max_h[k] is max height at step k

    # h[0] = 0 (initial height before any moves)
    min_h[0] = 0
    max_h[0] = 0

    # Forward pass
    for k in range(n): # k from 0 to n-1. Calculates for h[k+1] based on h[k] and d_input[k]
        l_obstacle_for_hkp1, r_obstacle_for_hkp1 = obstacles[k]
        
        prev_min_val = min_h[k]
        prev_max_val = max_h[k]
        current_d_spec = d_input[k]

        potential_next_min = -1 # Initialize with invalid values
        potential_next_max = -1

        if current_d_spec == 0:
            potential_next_min = prev_min_val + 0
            potential_next_max = prev_max_val + 0
        elif current_d_spec == 1:
            potential_next_min = prev_min_val + 1
            potential_next_max = prev_max_val + 1
        else: # current_d_spec == -1
            # d_input[k] can be 0 or 1.
            # If d_input[k] = 0, next height range is [prev_min_val, prev_max_val]
            # If d_input[k] = 1, next height range is [prev_min_val + 1, prev_max_val + 1]
            # Combined possible range for h[k] + d_input[k] is [prev_min_val, prev_max_val + 1]
            potential_next_min = prev_min_val
            potential_next_max = prev_max_val + 1
            
        actual_min_hkp1 = max(potential_next_min, l_obstacle_for_hkp1)
        actual_max_hkp1 = min(potential_next_max, r_obstacle_for_hkp1)

        if actual_min_hkp1 > actual_max_hkp1:
            print("-1")
            return

        min_h[k+1] = actual_min_hkp1
        max_h[k+1] = actual_max_hkp1

    # Backward pass for reconstruction
    ans_d = [0] * n
    h_chosen = [0] * (n + 1) 
    
    h_chosen[n] = min_h[n] # Pick a valid final height

    for k in range(n - 1, -1, -1): # k from n-1 down to 0. Determines d_input[k] (ans_d[k]) and h_chosen[k].
        current_d_spec = d_input[k]

        if current_d_spec != -1:
            ans_d[k] = current_d_spec
            h_chosen[k] = h_chosen[k+1] - ans_d[k]
        else: # d_input[k] == -1, need to choose d[k]
            # Option 1: Try ans_d[k] = 1
            # If d[k]=1, then h[k] = h[k+1] - 1. Check if this h[k] is valid.
            h_k_if_d1 = h_chosen[k+1] - 1
            option_d1_possible = (min_h[k] <= h_k_if_d1 <= max_h[k])
            
            # Option 2: Try ans_d[k] = 0
            # If d[k]=0, then h[k] = h[k+1] - 0. Check if this h[k] is valid.
            h_k_if_d0 = h_chosen[k+1] - 0
            option_d0_possible = (min_h[k] <= h_k_if_d0 <= max_h[k])

            # Prioritize one if both possible (e.g., d=1 to match h_chosen[n]=min_h[n] tendency)
            # Any valid choice works.
            if option_d1_possible:
                ans_d[k] = 1
                h_chosen[k] = h_k_if_d1
            elif option_d0_possible: # This must be true if d1 wasn't and a solution exists
                ans_d[k] = 0
                h_chosen[k] = h_k_if_d0
            else:
                # This state should ideally not be reached if the forward pass
                # determined a solution is possible and h_chosen[k+1] is valid.
                # It implies no valid predecessor h[k] for h_chosen[k+1].
                # For robustness in a contest, one might assert this path isn't taken,
                # but the theory guarantees one option is viable.
                pass 
                
    print(*(ans_d))

num_test_cases = int(sys.stdin.readline())
for _ in range(num_test_cases):
    solve()