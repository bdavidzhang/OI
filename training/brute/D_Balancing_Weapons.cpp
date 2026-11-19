// D. Balancing Weapons
// https://codeforces.com/contest/1814/problem/D  (3000 ms, 256 MB)
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
  int n,k;
  cin >> n >> k;
  vi f(n), d(n);
  for(int i = 0; i < n; ++i) cin >> f[i];
  for(int i = 0; i < n; ++i) cin >> d[i];

  int ans = 0;
  vector<pll> a;
  for(int i = 0 ; i < n; ++i){
    ll p = 1LL * f[i]  * d[i] ;
    a.emplace_back(max(p - k, 1LL), 1);
    a.emplace_back(p+1,-1);
  }

  sort(all(a));
  int res = 0;
  ll last = 0 ;
  
  for(auto [x,v] : a){
    if(res > 0){
      auto len = x - last;
      int val = 0;
      vector<pll> b;
      for(int i = 0; i < n; ++i){
        if(f[i] > k + 1){
           ll t = last - last % f[i];
           for (auto l : {t, t + f[i]}){
             ll L = max(last, l+1);
             ll R = min(x, l + f[i] - k);
             if(L < R){
               b.emplace_back(L,-1);
               b.emplace_back(R,1);
             }
           }
        }
      }
      b.emplace_back(x,0);
      ll lst = last;
      sort(all(b));
      for(auto [x,v] : b){
        if(x != lst && val == 0){
          ans = max(res,ans);
        }
        val += v;
        lst = x;
      }
    }
    res += v;
    last = x;
  }
  ans = n - ans;
  cout << ans << endl;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int T = 1;
  cin >> T;
  while (T--) solve();
  return 0;
}
