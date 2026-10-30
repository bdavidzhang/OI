#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

// const ll INF_LL = 1e18;

struct Edge {
    int to;
    ll z;
};

int N, M;
vector<ll> L, R;
vector<vector<Edge>> adj;

// DFS State variables
vector<bool> visited;
vector<int> s; // stores sign: 1 or -1
vector<ll> c;  // stores constant offset
vector<int> component_nodes;

bool is_fixed;
ll fixed_k_val;
bool possible; 

void dfs(int u) {
    component_nodes.push_back(u);
    visited[u] = true;

    for (auto& edge : adj[u]) {
        int v = edge.to;
        ll z = edge.z;

        if (!visited[v]) {
            // Propagate: a_u + a_v = z
            // (s_u*k + c_u) + (s_v*k + c_v) = z
            // s_v = -s_u
            // c_v = z - c_u
            s[v] = -s[u];
            c[v] = z - c[u];
            dfs(v);
            if (!possible) return; 
        } else {
            // Cycle detected: Check consistency
            // Case 1: Signs are different (k terms cancel)
            if (s[u] != s[v]) {
                if (c[u] + c[v] != z) {
                    possible = false;
                    return;
                }
            }
            // Case 2: Signs are same (k terms add up)
            else {
                ll rhs = z - c[u] - c[v];
                
                // Check parity: rhs must be divisible by 2
                if (abs(rhs) % 2 != 0) {
                    possible = false;
                    return;
                }

                ll derived_k = rhs / (2 * s[u]);

                if (is_fixed) {
                    if (fixed_k_val != derived_k) {
                        possible = false;
                        return;
                    }
                } else {
                    is_fixed = true;
                    fixed_k_val = derived_k;
                }
            }
        }
    }
}

void solve() {
    cin >> N >> M;
    
    L.assign(N + 1, 0);
    R.assign(N + 1, 0);
    adj.assign(N + 1, vector<Edge>());
    visited.assign(N + 1, false);
    s.assign(N + 1, 0);
    c.assign(N + 1, 0);
    
    for (int i = 1; i <= N; i++) cin >> L[i];
    for (int i = 1; i <= N; i++) cin >> R[i];
    
    for (int i = 0; i < M; i++) {
        int u, v;
        ll z;
        cin >> u >> v >> z;
        adj[u].push_back({v, z});
        adj[v].push_back({u, z});
    }

    possible = true;
    ll total_max_rods = 0;

    for (int i = 1; i <= N; i++) {
        if (visited[i]) continue;

        component_nodes.clear();
        is_fixed = false;
        fixed_k_val = 0;
        
        s[i] = 1; 
        c[i] = 0; 
        
        dfs(i);

        if (!possible) {
            cout << -1 << endl;
            return;
        }

        if (is_fixed) {
            ll current_count = 0;
            for (int u : component_nodes) {
                ll val = s[u] * fixed_k_val + c[u];
                if (val >= L[u] && val <= R[u]) {
                    current_count++;
                }
            }
            total_max_rods += current_count;
        } else {
            vector<pair<ll, int>> events;
            
            for (int u : component_nodes) {
                ll lower, upper;
                
                if (s[u] == 1) {
                    lower = L[u] - c[u];
                    upper = R[u] - c[u];
                } else {
                    lower = c[u] - R[u];
                    upper = c[u] - L[u];
                }

                if (lower <= upper) {
                    events.push_back({lower, 1});
                    events.push_back({upper + 1, -1});
                }
            }

            sort(events.begin(), events.end());

            ll max_overlap = 0;
            ll current_overlap = 0;
            
            for (size_t j = 0; j < events.size(); ) {
                ll current_coord = events[j].first;
                
                while (j < events.size() && events[j].first == current_coord) {
                    current_overlap += events[j].second;
                    j++;
                }
                max_overlap = max(max_overlap, current_overlap);
            }
            
            total_max_rods += max_overlap;
        }
    }

    cout << total_max_rods << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}