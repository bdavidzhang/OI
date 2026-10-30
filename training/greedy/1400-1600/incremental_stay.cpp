#include<bits/stdc++.h>
using namespace std;

using ll = long long;



void solve() {
    int n;
    cin >> n;
    vector<ll> a(2 * n + 1);
    for (int i = 1; i <= 2 * n; ++i) cin >> a[i];

    // prefix sums of differences, separated by parity
    vector<ll> d(2 * n, 0), pref0(2 * n, 0), pref1(2 * n, 0);
    for (int i = 1; i < 2 * n; ++i) {
        d[i] = a[i + 1] - a[i];
        pref0[i] = pref0[i - 1];
        pref1[i] = pref1[i - 1];
        if (i % 2 == 0) pref0[i] += d[i];
        else pref1[i] += d[i];
    }

    // outer[i] = sum_{j=1..i} (a[2n-j+1] - a[j])
    vector<ll> outer(n, 0);
    for (int i = 1; i < n; ++i)
        outer[i] = outer[i - 1] + (a[2 * n - i + 1] - a[i]);

    auto inside_sum = [&](int L, int R) -> ll {
        if (L > R) return 0;
        int parity = L % 2;
        if (parity == 0)
            return pref0[R - 1] - pref0[L - 1];
        else
            return pref1[R - 1] - pref1[L - 1];
    };

    vector<ll> ans(n + 1);
    for (int k = 1; k <= n; ++k) {
        int L = k, R = 2 * n - k + 1;
        ans[k] = outer[k - 1] + inside_sum(L, R);
    }

    for (int k = 1; k <= n; ++k)
        cout << ans[k] << (k == n ? '\n' : ' ');
}

int main(){
    
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}