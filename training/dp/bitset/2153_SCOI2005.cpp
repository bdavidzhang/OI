#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vll = vector<ll>;
using vpii = vector<pii>;
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()
#define endl '\n'


void solve() {
    int n, k;
    cin >> n >> k;
    vi pos, deg(1 << n);
    vector dp(n, vector<vll>(1 << n, vll(n * n + 10, 0)));

    for (int s = 0; s < (1 << n); ++s) {
        if (s & (s << 1))
            continue;

        pos.push_back(s);
        deg[s] = __builtin_popcount(s);
        dp[0][s][__builtin_popcount(s)] = 1;
    }

    auto good = [&](int a, int b) {
        return !(a & b) && !((a << 1) & b) && !(a & (b << 1));
    };


    for (int i = 1; i < n; ++i)
        for (auto j : pos)
            for (auto x : pos) {
                if (!good(j, x))
                    continue;

                for (int l = deg[j]; l <= k; ++l)
                    dp[i][j][l] += dp[i - 1][x][l - deg[j]];
            }

    ll ans = 0;

    for (auto j : pos)
        ans += dp[n - 1][j][k];

    cout << ans << endl;

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;

    while (T--)
        solve();

    return 0;
}
