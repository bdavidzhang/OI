tt = int(input())


for _ in range(tt):
    s_in = input()
    nums = [int(c) for c in s_in]
    n = len(nums)
    
    for cur_idx in range(n): # O(N) outer loop
        current_digit_at_pos = nums[cur_idx]
        
        # Variables to store the best valid improvement found for nums[cur_idx]
        # A valid improvement means new_val > current_digit_at_pos
        best_improvement_val = -1  # Stores the highest new_val > current_digit_at_pos
        best_improvement_source_idx = -1 # Stores the source index for best_improvement_val

        # Max distance (j_dist) to check is 9. So loop j_dist from 1 up to 9.
        # The upper limit for range should be 10 (to include j_dist=9).
        # Also, j_dist cannot exceed available elements to the right.
        # limit_for_j_dist_loop = min(n - cur_idx, 10)
        
        for j_dist in range(1, min(n - cur_idx, 10)): # Loop at most C=9 times
            swap_idx = cur_idx + j_dist
            val_at_swap_idx = nums[swap_idx]
            
            if val_at_swap_idx >= j_dist: # Check if the digit can survive the move
                new_potential_val = val_at_swap_idx - j_dist
                
                if new_potential_val > current_digit_at_pos:
                    # This is a potential improvement. Is it the best one found so far?
                    if new_potential_val > best_improvement_val:
                        best_improvement_val = new_potential_val
                        best_improvement_source_idx = swap_idx
                    elif new_potential_val == best_improvement_val:
                        # Tie in value: prefer smaller swap_idx.
                        # Since we iterate j_dist (and thus swap_idx) in increasing order,
                        # the current best_improvement_source_idx (if set for this value)
                        # is already the smallest. So, no update needed.
                        pass 
            
        if best_improvement_source_idx != -1: # If an improvement was found
            # Perform the shift. Cost is O(j_dist_chosen), which is O(C).
            # The value to place at cur_idx is best_improvement_val.
            
            # The digit from nums[best_improvement_source_idx] is moving.
            # Elements from nums[cur_idx]...nums[best_improvement_source_idx-1] shift right by one.
            
            # Store the digit that will be moved before it's overwritten
            # (though best_improvement_val is already its final value at cur_idx)
            
            for k_shift in range(best_improvement_source_idx, cur_idx, -1):
                nums[k_shift] = nums[k_shift-1]
            nums[cur_idx] = best_improvement_val
            
    s_out = "".join(map(str, nums))
    print(s_out)