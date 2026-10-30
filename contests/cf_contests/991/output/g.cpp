#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<vector<int>> adj(n + 1);

        for (int i = 0; i < n - 1; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int ans = 0;
        
        // dp1[v] = maximum sum for path ending at v going down into subtree
        // dp2[v] = maximum sum for path ending at v going up through parent  
        vector<int> dp1(n + 1, 0), dp2(n + 1, 0);
        
        // First DFS: calculate dp1 (downward paths)
        function<void(int, int)> dfs1 = [&](int v, int parent) {
            dp1[v] = adj[v].size() - 1; // path of length 0 (just vertex v)
            
            for (int u : adj[v]) {
                if (u != parent) {
                    dfs1(u, v);
                    // Extend path from v to u: v contributes (degree-2), then add dp1[u]
                    dp1[v] = max(dp1[v], (int)adj[v].size() - 2 + dp1[u]);
                }
            }
        };
        
        // Second DFS: calculate dp2 (upward paths) and find paths through each vertex
        function<void(int, int)> dfs2 = [&](int v, int parent) {
            ans = max(ans, dp1[v]);
            if (parent != -1) {
                ans = max(ans, dp2[v]);
            }
            
            // Find best and second best extensions
            vector<pair<int, int>> extensions; // {value, child_id (-1 for parent)}
            
            if (parent != -1) {
                extensions.push_back({dp2[v], -1});
            }
            
            for (int u : adj[v]) {
                if (u != parent) {
                    extensions.push_back({dp1[u], u});
                }
            }
            
            sort(extensions.rbegin(), extensions.rend());
            
            // Path passing through v (combining two extensions)
            if (extensions.size() >= 2) {
                ans = max(ans, (int)adj[v].size() - 2 + extensions[0].first + extensions[1].first);
            }
            
            // Calculate dp2 for children
            for (int u : adj[v]) {
                if (u != parent) {
                    dp2[u] = adj[v].size() - 1; // base case
                    
                    // Find best extension excluding path to u
                    for (auto& ext : extensions) {
                        if (ext.second != u) {
                            dp2[u] = max(dp2[u], (int)adj[v].size() - 2 + ext.first);
                            break;
                        }
                    }
                    
                    dfs2(u, v);
                }
            }
        };
        
        dfs1(1, -1);
        dfs2(1, -1);
        
        cout << ans << "\n";
    }

    return 0;
}