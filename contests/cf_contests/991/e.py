t = int(input())

for _ in range(t):
    a = input().strip()
    b = input().strip()
    s = input().strip()

    prev_dp = {}
    prev_dp[(0,0)] = 0

    for i in range(len(s)):
        cur_dp = {}
        cur_char = s[i] 
        
        for (pos_a,pos_b),mismatch in prev_dp.items():
            #take from a
            if pos_a < len(a):
                new_mismatch = mismatch + (0 if a[pos_a] == cur_char else 1)
                new_state = (pos_a+1,pos_b)
                if new_state not in cur_dp:
                    cur_dp[new_state] = new_mismatch
                else:
                    cur_dp[new_state] = min(new_mismatch,cur_dp[new_state])
            if pos_b < len(b):
                new_mismatch = mismatch + (0 if b[pos_b] == cur_char else 1)
                new_state = (pos_a,pos_b+1)
                if new_state not in cur_dp:
                    cur_dp[new_state] = new_mismatch
                else:
                    cur_dp[new_state] = min(new_mismatch,cur_dp[new_state])
        
        prev_dp = cur_dp
    
    result = min(prev_dp.values())
    print(result)

