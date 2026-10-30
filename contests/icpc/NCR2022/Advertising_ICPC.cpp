#include <iostream>
#include <vector>
#include <string>
#include <numeric>
#include <algorithm>

using namespace std;

// Modulo constant
const long long MOD = 998244353;

// Modular exponentiation to calculate total ways
long long power(long long base, long long exp) {
    long long res = 1;
    base %= MOD;
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * base) % MOD;
        base = (base * base) % MOD;
        exp /= 2;
    }
    return res;
}

// Helper to get character from its integer representation (0:I, 1:C, 2:P)
char get_char(int d) {
    if (d == 0) return 'I';
    if (d == 1) return 'C';
    return 'P';
}

// Helper to get integer representation from character
int get_digit(char c) {
    if (c == 'I') return 0;
    if (c == 'C') return 1;
    return 2;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<string> grid(n);
    int q_count = 0;
    for (int i = 0; i < n; ++i) {
        cin >> grid[i];
        for (char c : grid[i]) {
            if (c == '?') {
                q_count++;
            }
        }
    }

    // 1. Transpose the grid if n > m to ensure m is the smaller dimension
    if (n > m) {
        vector<string> new_grid(m, string(n, ' '));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                new_grid[j][i] = grid[i][j];
            }
        }
        grid = new_grid;
        swap(n, m);
    }

    long long total_ways = power(3, q_count);

    // --- DP to count ways with NO "ICPC" ---
    
    // Precompute powers of 3 for mask manipulation. Size m+2 for convenience.
    vector<int> pow3(m + 2);
    pow3[0] = 1;
    for (int i = 1; i <= m + 1; ++i) {
        pow3[i] = pow3[i - 1] * 3;
    }
    // The number of states is 3^(m+1)
    int lim = pow3[m + 1];

    // dp[k % 2][mask] for space optimization
    vector<vector<long long>> dp(2, vector<long long>(lim, 0));

    // Base case: before filling cell 0, there is 1 way (empty grid) with an empty mask
    dp[0][0] = 1;
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            int k = i * m + j;
            int current_dp_idx = k % 2;
            int next_dp_idx = (k + 1) % 2;
            fill(dp[next_dp_idx].begin(), dp[next_dp_idx].end(), 0);

            for (int mask = 0; mask < lim; ++mask) {
                if (dp[current_dp_idx][mask] == 0) continue;

                // Try placing each character ('I', 'C', 'P')
                for (int d = 0; d < 3; ++d) {
                    char current_char = get_char(d);

                    // Check if placement is consistent with the input grid
                    if (grid[i][j] != '?' && grid[i][j] != current_char) {
                        continue;
                    }

                    // Check if this placement forms an "ICPC" 2x2 subgrid
                    bool forms_icpc = false;
                    if (i > 0 && j > 0) {
                        int bot_right_d = d;
                        int bot_left_d = mask % 3;                           // Cell k-1
                        int top_right_d = (mask / pow3[m - 1]) % 3;           // Cell k-m
                        int top_left_d = (mask / pow3[m]) % 3;              // Cell k-m-1

                        if (get_char(top_left_d) == 'I' && get_char(top_right_d) == 'C' &&
                            get_char(bot_left_d) == 'P' && get_char(bot_right_d) == 'C') {
                            forms_icpc = true;
                        }
                    }

                    if (!forms_icpc) {
                        // If valid, transition to the next state by updating the mask
                        // Shift left, drop the oldest digit, add the new one
                        int new_mask = (mask % pow3[m]) * 3 + d;
                        dp[next_dp_idx][new_mask] = (dp[next_dp_idx][new_mask] + dp[current_dp_idx][mask]) % MOD;
                    }
                }
            }
        }
    }
    
    int final_dp_idx = (n * m) % 2;
    long long ways_with_none = 0;
    for (int mask = 0; mask < lim; ++mask) {
        ways_with_none = (ways_with_none + dp[final_dp_idx][mask]) % MOD;
    }

    //  (Total - None)
    long long ans = (total_ways - ways_with_none + MOD) % MOD;
    cout << ans << endl;

    return 0;
}