#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        int n;
        long long k;
        cin >> n >> k;
        int total = n * (n - 1) / 2;
        if (k > total) {
            cout << 0 << '\n';
            continue;
        }
        int S = total - (int)k; 

        vector<int> choose(n + 1, 0);
        for (int len = 0; len <= n; ++len) choose[len] = len * (len - 1) / 2;

        vector<vector<int>> parent(n + 1, vector<int>(S + 1, -1));
        parent[0][0] = 0; 

        for (int pos = 0; pos <= n; ++pos) {
            for (int s = 0; s <= S; ++s) {
                if (parent[pos][s] != -1) {
                    for (int len = 1; len <= n - pos; ++len) {
                        int ns = s + choose[len];
                        if (ns > S) break; 
                        if (parent[pos + len][ns] == -1) {
                            parent[pos + len][ns] = len;
                        }
                    }
                }
            }
        }

        if (parent[n][S] == -1) {
            cout << 0 << '\n';
            continue;
        }

        vector<int> runs;
        int pos = n, s = S;
        while (pos > 0) {
            int len = parent[pos][s];
            runs.push_back(len);
            pos -= len;
            s -= choose[len];
        }
        reverse(runs.begin(), runs.end());

        vector<int> perm;
        int cur = n;
        for (int len : runs) {
            vector<int> block;
            for (int i = 0; i < len; ++i) {
                block.push_back(cur--);
            }
            reverse(block.begin(), block.end());
            for (int x : block) perm.push_back(x);
        }

        for (int i = 0; i < n; ++i) {
            if (i) cout << ' ';
            cout << perm[i];
        }
        cout << '\n';
    }
    return 0;
}
