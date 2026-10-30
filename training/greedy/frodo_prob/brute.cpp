#include <bits/stdc++.h>
using namespace std;

int n, k;
vector<pair<int,int>> edges;
vector<int> adj[20];

int tree_height(int root, int parent) {
    int h = 0;
    for (int v : adj[root]) if (v != parent)
        h = max(h, tree_height(v, root));
    return h + 1;
}


int brute_force() {
    int m = edges.size();
    int best = n;

    // try all subsets of edges of size <= k
    vector<int> idx(m);
    iota(idx.begin(), idx.end(), 0);

    for (int mask = 0; mask < (1 << m); mask++) {
        if (__builtin_popcount(mask) > k) continue;

        // build adjacency list
        for (int i = 1; i <= n; i++) adj[i].clear();
        for (int i = 0; i < m; i++) {
            int u = edges[i].first, v = edges[i].second;
            if (mask & (1 << i)) {
                // edge is cut: reattach child to root (1)
                if (u == 1) adj[1].push_back(v), adj[v].push_back(1);
                else if (v == 1) adj[1].push_back(u), adj[u].push_back(1);
                else adj[1].push_back(v), adj[v].push_back(1); // assume u is parent
            } else {
                adj[u].push_back(v);
                adj[v].push_back(u);
            }
        }

        int h = tree_height(1, 0);
        best = min(best, h);
    }
    return best;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("brute_out.txt", "w", stdout);  // change to "brute_out.txt" for brute.cpp
#endif

   cin >> n >> k;
    edges.clear();
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        edges.push_back({u, v});
    }
    cout << brute_force() << "\n";
    return 0;
}
