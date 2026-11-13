// C. Books on a Shelf
// https://codeforces.com/contest/2290/problem/C  (2000 ms, 256 MB)
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
  vi a(n);
  for(int i = 0; i < n; ++i) cin >> a[i];
  sort(all(a));


  vi l, r;
  for(int i = 0; i< n; ++i){
    if(i % 2 == 0) l.push_back(a[i]);
    else r.push_back(a[i]);
  }

  auto uni = [&](vector<int> & v){
    if(sz(v) == 0) return 0;
    int cnt = 1;
    for(int i = 0; i< sz(v) -1; ++i){
      if(v[i] != v[i+1]) cnt++;
    }
    return cnt;
  }; 

  
  ll ans = uni(l) + uni(r);
  cout << ans << endl; 

  reverse(all(r));

  for(auto x : l ) cout << x << " ";
  for(auto x : r) cout << x << " ";
  cout << endl;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int T = 1;
  cin >> T;
  while (T--) solve();
  return 0;
}
