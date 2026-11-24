#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int LOG = 1;
    while ((1 << LOG) <= n) ++LOG;

    vector<vector<int>> up(LOG, vector<int>(n + 1));
    vector<int> depth(n + 1, -1);

    queue<int> bfs;
    bfs.push(1);
    depth[1] = 0;
    up[0][1] = 1;

    while (!bfs.empty()) {
        int u = bfs.front();
        bfs.pop();

        for (int v : adj[u]) {
            if (depth[v] != -1) continue;
            depth[v] = depth[u] + 1;
            up[0][v] = u;
            bfs.push(v);
        }
    }

    for (int k = 1; k < LOG; ++k) {
        for (int u = 1; u <= n; ++u) {
            up[k][u] = up[k - 1][up[k - 1][u]];
        }
    }

    auto lca = [&](int u, int v) {
        if (depth[u] < depth[v]) swap(u, v);

        int diff = depth[u] - depth[v];
        for (int k = 0; k < LOG; ++k) {
            if ((diff >> k) & 1) u = up[k][u];
        }

        if (u == v) return u;

        for (int k = LOG - 1; k >= 0; --k) {
            if (up[k][u] != up[k][v]) {
                u = up[k][u];
                v = up[k][v];
            }
        }

        return up[0][u];
    };

    while (q--) {
        int r, p;
        cin >> r >> p;

        ll d = depth[r] + depth[p]
          - 2 * depth[lca(r, p)];
        cout << n + d * (d + 1) / 2 << '\n';
    }
}
