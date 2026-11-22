// Not Adjacent
// https://atcoder.jp/contests/abc456/tasks/abc456_c  (2000 ms, 1024 MB)
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

void solve() {
  string s;
  cin >> s;
  int n = sz(s);
  vll dp(n);
  dp[0] = 1;
  char cur = s[0];
  for(int i = 1; i < n; ++i){
    if(s[i] == cur) dp[i] = 1;
    else{
      dp[i] = 1 + dp[i-1];
      dp[i] %= MOD;
      cur = s[i];
    }
  }

  ll ans = 0;
  for(int i = 0 ; i < n; ++i){
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
