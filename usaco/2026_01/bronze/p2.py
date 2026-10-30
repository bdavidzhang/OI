import sys

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return

    iterator = iter(input_data)
    try:
        t_val = next(iterator)
        k_val = next(iterator)
    except StopIteration:
        return
        
    num_test_cases = int(t_val)
    
    for _ in range(num_test_cases):
        try:
            FjString = int(next(iterator))
            s_str = next(iterator)
        except StopIteration:
            break
        
        if FjString % 2 != 0:
            print("-1")
            continue
            
        n_half = FjString // 2
        
        block_types = []
        for i in range(FjString):
            char = s_str[3*i]
            if char == 'C':
                block_types.append(0)
            elif char == 'O':
                block_types.append(1)
            else:
                block_types.append(2)
        
        is_one_op = True
        for i in range(n_half):
            if block_types[i] != block_types[i + n_half]:
                is_one_op = False
                break
        
        if is_one_op:
            print("1")
            res = [1] * (3 * FjString)
            print(*res)
        else:
            print("2")
            ans = [0] * (3 * FjString)
            
            for i in range(n_half):
                left_type = block_types[i]
                right_type = block_types[i + n_half]
                
                diff = (right_type - left_type) % 3
                
                l_base = 3 * i
                r_base = 3 * (i + n_half)
                
                if diff == 0:
                    for j in range(3):
                        ans[l_base + j] = 1
                        ans[r_base + j] = 1
                elif diff == 1:
                    ans[l_base] = 1
                    ans[l_base + 1] = 2
                    ans[l_base + 2] = 2
                    
                    ans[r_base] = 2
                    ans[r_base + 1] = 2
                    ans[r_base + 2] = 1
                elif diff == 2:
                    ans[l_base] = 2
                    ans[l_base + 1] = 2
                    ans[l_base + 2] = 1
                    
                    ans[r_base] = 1
                    ans[r_base + 1] = 2
                    ans[r_base + 2] = 2
            
            print(*ans)

if __name__ == '__main__':
    solve()