import sys
import subprocess
import random
import os

# CONFIGURATION
CMD = ["./solution"] # Adjust for Windows if needed (e.g., "solution.exe")
NUM_TESTS = 20
MAX_N = 100000       # Real problem constraint
MAX_K = 29           # Max power of 2

def generate_skewed_array():
    """
    Generates a 'Skewed' array where we flatten one side heavily
    and leave the other side pure, then concatenate.
    This creates extreme density differences.
    """
    k = random.randint(10, MAX_K)
    
    # Start with two identical blocks
    # We will 'pulverize' B into small pieces while keeping A large
    A = [2**k]
    B = [2**k]
    
    # 1. Flatten B extensively (The "Debris")
    # We flatten B until it has many elements or values become small
    while len(B) < 5000 and min(B) > 1:
        # Flatten a maximal element in B
        mx = max(B)
        if mx % 2 != 0: break
        
        # Pick a random occurrence of max to flatten
        candidates = [i for i, x in enumerate(B) if x == mx]
        if not candidates: break
        idx = random.choice(candidates)
        
        val = B[idx] // 2
        B[idx:idx+1] = [val, val]

    # 2. Flatten A just a little bit (The "Peaks")
    ops_a = random.randint(0, 5)
    for _ in range(ops_a):
        mx = max(A)
        if mx % 2 != 0: break
        candidates = [i for i, x in enumerate(A) if x == mx]
        idx = random.choice(candidates)
        val = A[idx] // 2
        A[idx:idx+1] = [val, val]

    # 3. Concatenate to mix them
    # Pattern: A + B (Dense + Sparse)
    # We do this a few times to build length
    arr = A + B
    
    # 4. Final random operations to ensure it's not too predictable
    # but keep the structure valid
    current_arr = list(arr)
    extra_ops = 5
    for _ in range(extra_ops):
        # Only flatten if we don't exceed N
        if len(current_arr) > MAX_N: break
        
        # Valid flatten on the combined array
        mx = max(current_arr)
        if mx % 2 != 0: continue
        
        candidates = [i for i, x in enumerate(current_arr) if x == mx]
        idx = random.choice(candidates)
        val = current_arr[idx] // 2
        current_arr[idx:idx+1] = [val, val]

    return current_arr

def run_test_case(test_idx):
    hidden_array = generate_skewed_array()
    
    # Enforce N limit by slicing if we accidentally went over
    # (Though slicing an invalid generated array breaks the logic, 
    # so we just regenerate if it's too big)
    if len(hidden_array) > MAX_N:
        return run_test_case(test_idx) # Retry
        
    n = len(hidden_array)
    true_max = max(hidden_array)
    
    # Interaction
    try:
        proc = subprocess.Popen(
            CMD,
            stdin=subprocess.PIPE,
            stdout=subprocess.PIPE,
            stderr=subprocess.PIPE,
            text=True,
            bufsize=0
        )
        
        # Protocol: Send T=1 then N
        proc.stdin.write(f"1\n{n}\n")
        proc.stdin.flush()
        
        queries = 0
        while True:
            line = proc.stdout.readline().strip()
            if not line: break
            
            if line.startswith("?"):
                queries += 1
                _, l, r = line.split()
                l, r = int(l), int(r)
                
                # Check bounds
                if l < 1 or r > n or l > r:
                    print(f"\n[Fail Case {test_idx}] Invalid query: {l} {r} (N={n})")
                    proc.kill()
                    return False
                
                # Respond
                ans_sum = sum(hidden_array[l-1:r])
                proc.stdin.write(f"{ans_sum}\n")
                proc.stdin.flush()
                
            elif line.startswith("!"):
                _, ans = line.split()
                ans = int(ans)
                proc.terminate()
                
                if ans == true_max:
                    sys.stdout.write(".")
                    sys.stdout.flush()
                    return True
                else:
                    print(f"\n[Fail Case {test_idx}] WRONG ANSWER")
                    print(f"  N: {n}")
                    print(f"  Expected: {true_max}")
                    print(f"  Got: {ans}")
                    print(f"  First 20 elements: {hidden_array[:20]}...")
                    return False
    except Exception as e:
        print(f"\nError: {e}")
        return False

if __name__ == "__main__":
    if not os.path.exists(CMD[0]):
        print("Compile your solution first!")
        sys.exit(1)
        
    print(f"Running {NUM_TESTS} Skewed Stress Tests...")
    for i in range(NUM_TESTS):
        if not run_test_case(i+1):
            sys.exit(1)
            
    print("\nAll stress tests passed.")