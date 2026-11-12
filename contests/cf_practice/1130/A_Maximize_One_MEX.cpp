// A. Maximize One MEX
// https://codeforces.com/contest/2272/problem/A  (1000 ms, 256 MB)
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

void solve() {
  int n, k;
  cin >> n >> k;
  vector<ll> a(n,0), v(n);
  map<ll,ll> b; 
  for(int i = 0; i < n; ++i){
    cin >> v[i];
  }
  for(int i = 0; i < k; ++i){
    a[v[i]] = 1;
    b[v[i]] = i;
  }
  ll idx;
  ll big = 0;
  bool ok = true;
  for(int i = 1; i <= n; ++i){
    if(a[i] == 0 && ok){
      idx = b[i];
      ok = false;
    }
    big = max(big,v[i]);
  }
  cout << b[big] << " " << idx << endl;


}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int T = 1;
  cin >> T;
  while (T--) solve();
  return 0;
}
