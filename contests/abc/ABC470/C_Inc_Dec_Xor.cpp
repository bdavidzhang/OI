// C - Inc, Dec, Xor
// https://atcoder.jp/contests/abc470/tasks/abc470_c  (2000 ms, 1024 MB)
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
  int n;
  cin >> n;
  vi v(n+1,0);
  unordered_set<int> act;
  ll ans = 0;
  int q;
  cin >> q;
  while(q--){ 
    int t; cin >> t;
    if(t == 1){
      int x;
      cin >> x;
      //cout << x << endl;
      ans = ans ^ v[x] ^ (v[x]+1);
      v[x]++;
      act.insert(x);
    }
    else{
      for(auto it = act.begin(); it != act.end();){
        int x = *it;
        ans ^= v[x] ^ (v[x] - 1);
        v[x]--;
        if(v[x] == 0) it = act.erase(it);
        else it++;
      }
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
