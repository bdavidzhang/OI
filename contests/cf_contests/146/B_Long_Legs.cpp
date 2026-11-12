// B. Long Legs
// https://codeforces.com/contest/1814/problem/B  (2000 ms, 256 MB)
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
#define endl '\n'



void solve() {
  int a,b;
  cin >> a >> b;

  int ans = 0;

  int x = min(a,b), y = max(a,b);
  int d = gcd(a,b);
  
  int cur = LLONG_MAX - 19;
  cout << d << endl;
  cout << 8 % d << endl;
  for(int k = d; k*k <= y; ++k){
    if(y % k == 0){
      cout << k << endl;
      cur = min(cur, k - d + y / k);
    }
  }
  cout << cur << endl;
  ans = cur + x / d + d - 1; 


  cout << ans << endl;  
}


signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int T = 1;
  cin >> T;
  while (T--) solve();
  return 0;
}
