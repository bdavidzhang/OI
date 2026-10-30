import sys

# We no longer need to set the recursion limit
# sys.setrecursionlimit(2 * 10**6) 

def solve():
    """
    Solves a single test case with an iterative DFS.
    """
    try:
        n, m = map(int, sys.stdin.readline().split())
        grid = [sys.stdin.readline().strip() for _ in range(n)]
    except (IOError, ValueError):
        return

    # --- Step 1: Find all existing components using ITERATIVE DFS ---
    visited = [[False] * m for _ in range(n)]
    component_id_grid = [[0] * m for _ in range(n)]
    component_sizes = [0]  # 1-based indexing for component IDs

    current_id_counter = 1
    for r_start in range(n):
        for c_start in range(m):
            if grid[r_start][c_start] == '#' and not visited[r_start][c_start]:
                # Found the start of a new, unvisited component
                size = 0
                stack = [(r_start, c_start)]
                visited[r_start][c_start] = True # Mark as visited immediately

                while stack:
                    r, c = stack.pop()
                    size += 1
                    component_id_grid[r][c] = current_id_counter
                    
                    # Explore neighbors
                    for dr, dc in [(0, 1), (0, -1), (1, 0), (-1, 0)]:
                        nr, nc = r + dr, c + dc
                        
                        if 0 <= nr < n and 0 <= nc < m and \
                           not visited[nr][nc] and grid[nr][nc] == '#':
                            visited[nr][nc] = True # Mark before adding to stack
                            stack.append((nr, nc))
                            
                component_sizes.append(size)
                current_id_counter += 1

    # --- Step 2 & 3: Calculate scores (this part remains the same) ---
    max_size = max(component_sizes[1:]) if len(component_sizes) > 1 else 0
    
    # Calculate scores for filling each ROW
    for r in range(n):
        dots_in_row = grid[r].count('.')
        adjacent_ids = set()
        
        for c in range(m):
            for dr in [-1, 0, 1]:
                nr = r + dr
                if 0 <= nr < n:
                    if component_id_grid[nr][c] != 0:
                        adjacent_ids.add(component_id_grid[nr][c])
        
        merged_size = sum(component_sizes[cid] for cid in adjacent_ids)
        max_size = max(max_size, dots_in_row + merged_size)

    # Calculate scores for filling each COLUMN
    for c in range(m):
        dots_in_col = 0
        adjacent_ids = set()
        
        for r in range(n):
            if grid[r][c] == '.':
                dots_in_col += 1
            
            for dc in [-1, 0, 1]:
                nc = c + dc
                if 0 <= nc < m:
                    if component_id_grid[r][nc] != 0:
                        adjacent_ids.add(component_id_grid[r][nc])

        merged_size = sum(component_sizes[cid] for cid in adjacent_ids)
        max_size = max(max_size, dots_in_col + merged_size)

    print(max_size)


def main():
    """
    Main function to handle multiple test cases.
    """
    try:
        t = int(sys.stdin.readline())
        for _ in range(t):
            solve()
    except (IOError, ValueError):
        return

if __name__ == "__main__":
    main()