#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;

#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()

const int INF = 1e9;
const ll LINF = 4e18;
const int MOD = 998244353;

void solve() {
  int n;
  cin >> n;
  int h = 1;
  while (h * 2 <= n) h *= 2;
  vi p;
  for (int v = 0; v < h; v++) p.push_back(v), p.push_back(v);
  for (int v = 2 * h - 1; v >= h; v--) p.push_back(v), p.push_back(v);
  cout << sz(p) - 1 << endl;
  for (int i = 1; i < sz(p); i++){
    cout << (p[i] ^ p[i - 1]) << " \n"[i == sz(p) - 1];
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t = 1;
  cin >> t;
  while (t--) solve();
  return 0;
}
