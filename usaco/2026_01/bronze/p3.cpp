#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N, K;
    cin >> N >> K;
    
    int Q;
    cin >> Q;
    
    vector<vector<long long>> grid(N + 1, vector<long long>(N + 1, 0));
    
    int max_row = N - K + 1;
    int max_col = N - K + 1;
    vector<vector<long long>> square_sum(max_row + 1, vector<long long>(max_col + 1, 0));
    
    long long max_attr = 0;
    
    for (int q = 0; q < Q; q++) {
        int r, c;
        long long v;
        cin >> r >> c >> v;
        
        long long delta = v - grid[r][c];
        grid[r][c] = v;
        
        
        int min_i = max(1, r - K + 1);
        int max_i = min(r, max_row);
        int min_j = max(1, c - K + 1);
        int max_j = min(c, max_col);
        
        for (int i = min_i; i <= max_i; i++) {
            for (int j = min_j; j <= max_j; j++) {
                square_sum[i][j] += delta;
                max_attr = max(max_attr, square_sum[i][j]);
            }
        }
        
        cout << max_attr << "\n";
    }
    
    return 0;
}