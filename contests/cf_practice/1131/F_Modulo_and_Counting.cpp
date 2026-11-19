// F. Modulo and Counting
// https://codeforces.com/contest/2278/problem/F  (2000 ms, 512 MB)
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

constexpr ll MOD = 998244353;

ll brute(int n, int m){
  ll ans = 0;

  auto dfs = [&](auto && self, int pos, int pre, int sum) -> void {
    if(sum > m) return;  

    if(pos > m) {
      if(sum == 0) ans++;
      return;

    }

    for(int x = 1; x <= pre; ++x){
      int nxt = sum;

      if(pos > 1) nxt += pre % x;

      self(self,pos+1,x,nxt);
    }
  };


  dfs(dfs,1,m+2,0);
  return ans;
  
}



void solve() {
  int n,m;
  cin >> n >> m;
  cout << brute(n,m) << endl;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int T = 1;
  cin >> T;
  while (T--) solve();
  return 0;
}
