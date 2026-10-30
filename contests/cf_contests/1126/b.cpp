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
  int n, k;
  cin >> n >> k;
  vi cnt(n + 2, 0);
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    cnt[a]++;
  }
  int m = 0;
  while (cnt[m] >= 2 * k) m++;
  cout << (cnt[m] == 2 * k - 1 ? "YES" : "NO") << endl;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t = 1;
  cin >> t;
  while (t--) solve();
  return 0;
}
