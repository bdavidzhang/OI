// C. Monster Game
// https://codeforces.com/group/tKC7z9Nm0A/contest/732255/problem/C  (2000 ms, 256 MB)
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

void debug(string s, vi & a){
  cout << s << ":";
  for(auto & x : a) cout << x << " ";
  cout << endl;
}


void solve() {
  int n;
  cin >> n;
  vi a(n+1), b(n+1); 
  vll pre(n+1);
  for(int i = 1; i <= n; ++i) cin >> a[i];
  for(int i = 1; i <= n; ++i){
    cin >> b[i];
    pre[i] = pre[i-1] + b[i];
  }

  sort(a.begin()+1,a.end());
  reverse(a.begin()+1,a.end());

 // debug("a",a);
 // debug("b",b); 
 // debug("pre",pre);


  ll ans = LLONG_MIN;
  for(int k = 1; k <= n; ++k){
    int x = a[k];
    int idx = upper_bound(pre.begin()+1, pre.end(),k) - pre.begin() - 1;
    vi temp = {x,idx};
    //debug("x idx",temp);
    ans = max(ans, 1LL * idx * x);
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
