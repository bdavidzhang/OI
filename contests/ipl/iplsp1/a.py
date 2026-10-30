class Graph:
    def __init__(self, vertices):
        """
        Initialize the graph with a given number of vertices.
        
        Args:
            vertices (int): Number of vertices in the graph
        """

        self.V = vertices
        self.graph = [[] for _ in range(vertices)]
    
    def add(self, u, v):
        """
        Add an undirected edge between vertices u and v.
        
        Args:
            u (int): First vertex
            v (int): Second vertex
        """
        # Add edge from u to v
        self.graph[u].append(v)
        # Add edge from v to u (for undirected graph)
        self.graph[v].append(u)
    
    def dfs(self, v, visited):
        """
        Depth-First Search to explore all vertices in a connected component.
        
        Args:
            v (int): Starting vertex
            visited (list): List to track visited vertices
        """
        # Mark the current vertex as visited
        visited[v] = True
        
        # Explore all adjacent vertices that haven't been visited
        for neighbor in self.graph[v]:
            if not visited[neighbor]:
                self.dfs(neighbor, visited)
    
    def count_connected_components(self):
        """
        Count the number of connected components in the graph.
        
        Returns:
            int: Number of connected components
        """
        visited = [False] * self.V
        
        components = 0
        
        for v in range(self.V):
            if not visited[v]:
                self.dfs(v, visited)
                components += 1
        
        return components

def main():
    
    n = int(input())
    g = Graph(n-1)
    for i in range(n):
        t = int(input())
        if t != -1:
            g.add(i,t)
        
    print( g.count_connected_components())

if __name__ == "__main__":
    main()