t = int(input())

for _ in range(t):
    stack = input()
    run_tot = 0
    split_idx = []
    for i in range(len(stack)):
        if(stack[i] == '('):
            run_tot += 1
        else: 
            run_tot -= 1
        if run_tot == 0: 
            split_idx.append(i)
    if split_idx != [len(stack)-1]:
        print("YES")
    else:
        print("NO")

            
    
    