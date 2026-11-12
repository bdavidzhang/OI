#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
  int n, q;
  cin >> n >> q;

  vector<ll> pre(n + 1), idx(n + 1), sum(n + 1);

  for (int i = 1; i <= n; ++i) {
    ll a;
    cin >> a;
    pre[i] = pre[i - 1] + a;
    idx[i] = idx[i - 1] + i;
    sum[i] = sum[i - 1] + pre[i];
}

  auto F = [&](ll x) -> ll {
    int k = upper_bound(idx.begin(), idx.end(), x) - idx.begin() - 1;

    return sum[k] + pre[x - idx[k]];
  };

  while (q--) {
      ll l, r;
      cin >> l >> r;
      cout << F(r) - F(l - 1) << '\n';
  }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}