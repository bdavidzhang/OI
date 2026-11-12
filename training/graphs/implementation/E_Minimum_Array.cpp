// E. Minimum Array
// https://codeforces.com/problemset/problem/1157/E?utm_source=chatgpt.com  (2000 ms, 256 MB)
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
  vi a(n), b(n);
  multiset<int> s;
  for(int i = 0; i < n; ++i){
    cin >> a[i];
  }
 
  for(int i = 0; i < n; ++i){
    cin >> b[i];
    s.insert(b[i]);
  }

  vi c(n);
  for(int i = 0 ;i < n; ++i){
    auto it = s.lower_bound(n-a[i]); 
    if(it != s.end()){
      int x = *it;
      c[i] = (x + a[i]) % n;
      s.erase(it);
    }else{
      auto it2 = s.lower_bound(0);
      int x = *it2; 
      c[i] = (x+ a[i]) % n;
      s.erase(it2);
    }
  }
  for(auto x : c) cout << x << " ";
  cout << endl;
 
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int T = 1;
  while (T--) solve();
  return 0;
}
