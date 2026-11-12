# Johnson APSP 

weighted edge can have positive / negative weights.
but no negative rings allowed. 

This is for looking for all pairs shortest path. 

Comparison: 
- No negative edge, we can do dijkstra at all points with complexity $O(n * m * log(n))$
- Some negative edges, run bellman ford at all points with complexity $O(n * n * m)$
- Some negative edges, run floyd with $O(n * n * n)$.

Is there a way to get all the edge weights into nonnegative values and run dijkstra?
The easy idea is to add some val to every weight. 

e.g.
x -> a (-5)
a -> b (-5)
b -> y (-4)
x -> c (-6)
c -> y (-6)
the best path is x->a->b->y, but when we add 6 to everything, the path becomes 
x -> c -> y.

## idea
1. every edge becomes nonnegative
2. every point runs dijkstra
3. find shortest path between any two points 

Setup a super source $S$ connecting to all points with edge weight $0$. 
We come up with a lowest potential array $h$, initialized to $- \infty$, starting at $h[S] = 0$.
what is the lowest potential for $h$ for every point? 

This can be done via bellman ford (dp) or spfa. 

Once the values are finalized, for each edge u->v (w), we update 
$$
w = w + h[u] - h[v]
$$

so the augmented graph has nonnegative weights (why?).

This is becuase from the definition of $h$, we cannot have 
$$
h[u] + w < h[v]
$$
hence the converse is true: 
$$
h[u] + w \ge h[v]
$$
which means 
$$
w + h[u] - h[v] \ge 0.
$$















