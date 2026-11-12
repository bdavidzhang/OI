// A. Coins
// https://codeforces.com/contest/1814/problem/A  (2000 ms, 256 MB)
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
#define int long long



void solve() {
  int n, k;
  cin >> n >> k;

  if(k % 2 == 0){
    if(n % 2 == 0) cout << "Yes" << endl;
    else cout << "No" << endl;
  }else{
  int res = 2 * k - k - 2;
  if (res < n) cout << "Yes" << endl;
  else cout << "No" << endl;
  }
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int T = 1;
  cin >> T;
  while (T--) solve();
  return 0;
}
