#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
constexpr i64 MOD = 998244353;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    i64 t;
    cin >> n >> t;

    vector<int> a(n);
    i64 idle = t;
    for (int &x : a) {
        cin >> x;
        idle -= x;
    }

    i64 ans = idle + 1;
    i64 choices = n + idle + 1;

    for (int i = 0; i < n; ++i) {
        if (i > 0) {
            ans = ans * choices % MOD;
        }
        choices += a[i] - 1;
    }

    cout << ans << '\n';
}
