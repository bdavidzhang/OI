// Not Adjacent 2
// https://atcoder.jp/contests/abc456/tasks/abc456_d  (2000 ms, 1024 MB)
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


const int MOD = 998244353;

void debug(string s, vll & v){
  cout << s << endl;
  for(auto x : v) cout << x << " ";
  cout << endl;
}

void solve() {
  string s;
  cin >> s;
  int n = sz(s);
  vll dp(3); // a,b,c


  auto idx = [&](char c) -> int{
    return c - 'a';
  };

  for(int i = 0; i < n; ++i){
    for(char c : {'a','b','c'}){
      if(s[i] != c) dp[idx(s[i])] += dp[idx(c)];
      dp[idx(s[i])] %= MOD;
    }
    dp[idx(s[i])]++;
    dp[idx(s[i])] %= MOD;
  }

  //debug("dp",dp);

  ll ans = 0;
  for(int i = 0 ; i < 3; ++i){
    ans += dp[i] % MOD;
    ans %= MOD;
  }
  cout << ans << endl;

}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int T = 1;
  while (T--) solve();
  return 0;
}

