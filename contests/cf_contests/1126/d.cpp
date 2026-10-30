#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<ll>;

#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()

const int INF = 1e9;
const ll LINF = 4e18;
const int MOD = 998244353;

void solve() {
  int n;
  ll m, k;
  cin >> n >> m >> k;
  vll l(n), r(n), pre(n + 1, 0);

  for (int i = 0; i < n; i++) {
    cin >> l[i] >> r[i];
    pre[i + 1] = pre[i] + (r[i] - l[i] + 1);
  }


  auto cnt = [&](ll x) {
    int i = upper_bound(all(l), x) - l.begin();
    if (i == 0) return 0LL;
    return pre[i - 1] + min(x, r[i - 1]) - l[i - 1] + 1;
  };


  auto f = [&](ll s) { 
    return cnt(s + m - 1) - cnt(s - 1); 
  };

  vector<ll> bp = {1};
  for (int i = 0; i < n; i++) {
    for (ll s : {l[i], r[i] + 1, l[i] - m, r[i] + 1 - m}) {
      if (s >= 1) bp.push_back(s);
    }
  }
  sort(all(bp));
  bp.erase(unique(all(bp)), bp.end());
  for (int i = 0; i + 1 < sz(bp); i++) {
    ll a = f(bp[i]), b = f(bp[i + 1]);

    if (min(a, b) <= k && k <= max(a, b)) {
      cout << bp[i] + abs(k - a) << endl;
      return;
    }
  }

  cout << -1 << endl
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t = 1;
  cin >> t;
  while (t--) solve();
  return 0;
}
