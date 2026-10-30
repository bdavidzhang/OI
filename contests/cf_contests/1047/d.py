import sys
from collections import defaultdict

def solve():
    n = int(sys.stdin.readline())
    b = list(map(int, sys.stdin.readline().split()))

    groups = defaultdict(list)
    for i, val in enumerate(b):
        groups[val].append(i)

    for b_val, indices in groups.items():
        if len(indices) % b_val != 0:
            print(-1)
            return

    a = [0] * n
    val_counter = 1
    
    for b_val in sorted(groups.keys()):
        indices = groups[b_val]
        
        for i in range(0, len(indices), b_val):
            for j in range(b_val):
                original_index = indices[i + j]
                a[original_index] = val_counter
            
            val_counter += 1
            
    print(' '.join(map(str, a))) 

t = int(sys.stdin.readline())
for _ in range(t):
    solve()

