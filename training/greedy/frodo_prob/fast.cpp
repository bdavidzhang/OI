#include <iostream>
#include <vector>
#include <algorithm>

// Global variables for convenience in competitive programming style.
int n;
int k;
std::vector<std::vector<int>> adj;

/**
 * @brief Performs a DFS to calculate operations needed for a target height 'h'.
 * * @param u The current node.
 * @param p The parent of the current node.
 * @param h The target height we are checking.
 * @param ops A reference to the counter for the number of operations.
 * @return The length of the longest path starting at 'u' downwards after optimal cuts.
 */
int dfs(int u, int p, const int h, int& ops) {
    int max_len = 0;
    for (int v : adj[u]) {
        if (v == p) continue;
        max_len = std::max(max_len, 1 + dfs(v, u, h, ops));
    }
    
    // Condition to cut the edge (p, u).
    // This is necessary if u is at depth 2 or more (its parent p is not the root or a dummy parent),
    // and the path from p through u downwards would form a path of length exactly h.
    // Such a path must be cut because the total path from the actual root would be >= 1 + h.
    if (p != 1 && p != 0 && max_len == h - 1) {
        ops++;
        // After cutting, this branch is re-rooted. From p's perspective, its length is 0.
        // We return -1, so the caller (p) computes length as 1 + (-1) = 0.
        return -1;
    }
    
    return max_len;
}

/**
 * @brief Checks if it's possible to achieve a tree height of 'h' with at most 'k' operations.
 */
bool is_possible(int h) {
    if (h == 0) return n == 1; // Height 0 is only possible for a single-node tree.
    int ops_count = 0;
    // We start the DFS from the root (node 1) with a dummy parent (0).
    dfs(1, 0, h, ops_count);
    return ops_count <= k;
}

int main() {
    // Fast I/O
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("fast_out.txt","w",stdout);
#endif
    std::cin >> n >> k;
    adj.resize(n + 1);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        std::cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    if (n == 1) {
        std::cout << 0 << std::endl;
        return 0;
    }

    int low = 1, high = n - 1, ans = n - 1;

    // Binary search for the minimum possible height.
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (is_possible(mid)) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    std::cout << ans << std::endl;

    return 0;
}