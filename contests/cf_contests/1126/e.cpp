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
  int n, k;
  cin >> n >> k;
  vll freq(n + 1, 0);
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    freq[a]++;
  }

  auto check = [&](ll s) {
    ll c = n + k + 2 * s;
    vll cnt = freq;
    ll ps = 0, sp = 0;



    for (int y = n; y >= 1; y--) {
      ll good = max(0LL, c - y - ps);
      if (cnt[y] > good) {
        ll extra = cnt[y] - good;
        if (y == 1) return false;
        sp += extra;
        if (sp > s) return false;
        cnt[(y + 1) / 2] += 2 * extra;
        ps += good;
      } else {
        ps += cnt[y];
      }
    }
    return true;
  };


  ll lo = 0, hi = 2LL * n;
  while (lo < hi) {
    ll mid = (lo + hi) / 2;
    if (check(mid)) hi = mid;
    else lo = mid + 1;
  }

  cout << n + 2 * lo << "\n";
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t = 1;
  cin >> t;
  while (t--) solve();
  return 0;
}
