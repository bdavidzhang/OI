from math import comb
from collections import defaultdict

def distinct_pairs(n):
    return comb(n, 2)

def find_connected_components(n, edges):
    graph = defaultdict(list)
    for u, v in edges:
        graph[u].append(v)
        graph[v].append(u)

    visited = [False] * n
    components = []

    def dfs(node, component):
        stack = [node]
        while stack:
            curr = stack.pop()
            for neighbor in graph[curr]:
                if not visited[neighbor]:
                    visited[neighbor] = True
                    component.append(neighbor)
                    stack.append(neighbor)

    for i in range(n):
        if not visited[i]:
            visited[i] = True
            component = [i]
            dfs(i, component)
            components.append(component)

    return components

def count_valid_tickets(components):
    total_valid_pairs = 0
    for component in components:
        size = len(component)
        if size > 1:
            total_valid_pairs += comb(size, 2)
    return total_valid_pairs

def calculate_probability(total_pairs, valid_tickets):
    if total_pairs == 0:
        return 0.0
    return valid_tickets / total_pairs

# Main function to solve the problem
def solve(n, m, edges):
    total_pairs = distinct_pairs(n)
    components = find_connected_components(n, edges)
    valid_tickets = count_valid_tickets(components)
    probability = calculate_probability(total_pairs, valid_tickets)
    return probability

# Example usage
n = 5  # number of cities
m = 3  # number of claimed rail segments
edges = [(0, 1), (1, 2), (3, 4)]  # claimed rail segments

result = solve(n, m, edges)
print(f"Probability of earning points: {result:.6f}")
