#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()

const int INF = 1e9;
const ll LINF = 4e18;
const int MOD = 998244353;

void solve() {
  int x,y;
  cin >> x >> y;
  if (y > x + 1) {
    cout << -1 << endl;
    return;
  }
  if ((x - y) % 2 == 0) cout << x << endl;
  else cout << x + 1 << endl;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t = 1;
  cin >> t;
  while (t--) solve();
  return 0;
}
