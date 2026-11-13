// E. Avalanche
// https://codeforces.com/contest/2290/problem/E  (2000 ms, 256 MB)
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
  vi a(n+1);
  for(int i = 1; i <= n; ++i){
    cin >> a[i];
  }

  int p = 0;
  for(int i = 1; i <= n; i += k + 1){
    p += a[i] % 2;
    p %= 2;
  }
  if(p == 1) cout << "Alice" << endl;
  else cout << "Bob" << endl;


}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int T = 1;
  cin >> T;
  while (T--) solve();
  return 0;
}
