#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    long long k;
    cin >> n >> k;

    if (k == (long long)n * n - 1) {
        cout << "NO\n";
        return;
    }

    cout << "YES\n";
    vector<string> grid(n, string(n, ' '));

    int full_escape_rows = k / n;
    int mixed_row_escapes = k % n;

    for (int i = 0; i < full_escape_rows; ++i) {
        for (int j = 0; j < n; ++j) {
            grid[i][j] = 'U';
        }
    }

    if (full_escape_rows < n) {
        int row = full_escape_rows;
        
        for (int j = 0; j < mixed_row_escapes; ++j) {
            grid[row][j] = 'U';
        }
        
        int trap_segment_len = n - mixed_row_escapes;
        if (trap_segment_len > 0) {
            if (trap_segment_len == 1) {
                grid[row][n - 1] = 'D';
            }
            else {
                grid[row][mixed_row_escapes] = 'R';
                for (int j = mixed_row_escapes + 1; j < n; ++j) {
                    grid[row][j] = 'L';
                }
            }
        }
    }

    for (int i = full_escape_rows + 1; i < n; ++i) {
        grid[i][0] = 'R';
        for (int j = 1; j < n; ++j) {
            grid[i][j] = 'L';
        }
    }

    for (int i = 0; i < n; ++i) {
        cout << grid[i] << "\n";
    }
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