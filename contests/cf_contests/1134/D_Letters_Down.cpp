// D. Letters Down
// https://codeforces.com/contest/2290/problem/D  (2000 ms, 256 MB)
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
  int n;
  cin >> n;
  string s;
  cin >> s;
  ll ans = 0;

  vi a(n);
  for(int i = 0; i < n; ++i){
    a[i] = s[i] - 'a' + 1;
  }


  while(true){
    bool ok = true;
    pii big = {0,0};
    for(int i = 0; 2 * i < n; ++i){
      int j = n - 1 - i;
      if(a[i] == a[j]) continue;
      ok = false;
      int x = big.first;
      if(x < max(a[i],a[j])){
        big.first = max(a[i],a[j]);
        big.second = min(a[i],a[j]); 
      }
    }
    while(big.first != big.second){
      for(int i = 0; i < n; ++i){
        if(a[i] == big.first) a[i]--;
      }
      ans++;
      big.first--;
    }
    if(ok) break;
  }
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
