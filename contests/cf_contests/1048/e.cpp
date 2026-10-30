#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;
vector<int> adj[1005];
int n, k;
vector<vector<int>> dp[1005];

void solve_dfs(int u, int L) {
    // Initialize DP table for node u
    dp[u].assign(L + 1, vector<int>(L + 1, INF));

    if (adj[u].empty()) { // Base case: u is a leaf
        dp[u][0][0] = 0;
        dp[u][1][0] = 1;
        dp[u][0][1] = 0;
        return;
    }

    // Recursively solve for all children
    for (int v : adj[u]) {
        solve_dfs(v, L);
    }

    dp[u][0][0] = 0;
    for (int l = 1; l <= L; ++l) {
        for (int z = 0; z <= l; ++z) {
            int o = l - z;

            // Option 1: Don't use u's label in LCS
            long long sum_skip = 0;
            for (int v : adj[u]) {
                if (dp[v][z][o] >= INF) {
                    sum_skip = INF;
                    break;
                }
                sum_skip += dp[v][z][o];
            }

            // Option 2: Use u's label as a '0'
            long long sum_use0 = INF;
            if (z > 0) {
                sum_use0 = 1;
                for (int v : adj[u]) {
                    if (dp[v][z - 1][o] >= INF) {
                        sum_use0 = INF;
                        break;
                    }
                    sum_use0 += dp[v][z - 1][o];
                }
            }

            // Option 3: Use u's label as a '1'
            long long sum_use1 = INF;
            if (o > 0) {
                sum_use1 = 0;
                for (int v : adj[u]) {
                    if (dp[v][z][o - 1] >= INF) {
                        sum_use1 = INF;
                        break;
                    }
                    sum_use1 += dp[v][z][o - 1];
                }
            }
            
            long long res = min({sum_skip, sum_use0, sum_use1});
            if (res < INF) {
                dp[u][z][o] = res;
            }
        }
    }
}

bool check(int L) {
    if (L == 0) return true;
    solve_dfs(1, L);
    
    int min_zeros = INF;
    for (int z = 0; z <= L; ++z) {
        min_zeros = min(min_zeros, dp[1][z][L - z]);
    }
    return min_zeros <= k;
}

void solve() {
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) {
        adj[i].clear();
    }
    for (int i = 2; i <= n; ++i) {
        int p;
        cin >> p;
        adj[p].push_back(i);
    }

    int low = 0, high = n, ans = 0;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (check(mid)) {
            ans = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}