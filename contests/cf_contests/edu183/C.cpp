#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        int n;
        string s;
        cin >> n >> s;
        vector<int> diff(n + 1, 0);
        for (int i = 1; i <= n; ++i)
            diff[i] = diff[i - 1] + (s[i - 1] == 'a' ? 1 : -1);

        int total = diff[n];
        if (total == 0) {
            cout << 0 << '\n';
            continue;
        }

        unordered_map<int,int> last;
        last.reserve((size_t) (n * 2));
        last.max_load_factor(0.7f);

        last[diff[0]] = 0;
        int ans = n + 1;
        for (int i = 1; i <= n; ++i) {
            int want = diff[i] - total;          
            auto it = last.find(want);
            if (it != last.end()) {
                ans = min(ans, i - it->second); 
            }
            last[diff[i]] = i;                  
        }

        if (ans == n + 1 || ans == n) cout << -1 << '\n';
        else cout << ans << '\n';
    }
    return 0;
}
