// D2. Maximum And Queries (hard version)
// https://codeforces.com/contest/1903/problem/D2  (7000 ms, 512 MB)
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
  int n, q;
  cin >> n >> q;
  vll f(1 << 20);
  vi a(n);
  for(int i = 0; i < n; ++i) cin >> a[i];
  
  for(int k = 0; k < 20; ++k){
    vll s(1 << (19 - k)), c(1 << (19 - k));
    for(int i = 0 ;i < n; ++i){
      if(~a[i] >> k & 1){
        s[a[i] >> (k + 1)] += a[i] & ((1 << k) - 1);
        c[a[i] >> (k + 1)] += 1;
      }
    }
    for(int i = 1; i < (1 << (19 - k)); i <<= 1){
      for(int j = 0; j < (1 << (19 - k)); j += 2 * i){
        for(int l = 0; l < i; ++l){
          s[j+l] += s[i + j + l];
          c[j+l] += c[i +j + l];
        }
      }
    }
    for(int x = 0 ; x < (1 << 20); x++){
      if(x >> k & 1){
        int y = x >> (k + 1);
        f[x] += c[y] * (x & ((1 << (k+1)) - 1)) - s[y];
      }
    }
  }
  for(int i = (1 << 20) - 2; i >= 0; --i){
    f[i] = min(f[i], f[i+1]);
  }
  while(q--){
    ll k;
    cin >> k;
    ll ans = upper_bound(all(f), k) - f.begin() - 1;
    if(k >= f.back()){
      ans += (k - f.back()) / n;
    }
    cout << ans << endl;
  }

}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int T = 1;
  while (T--) solve();
  return 0;
}
