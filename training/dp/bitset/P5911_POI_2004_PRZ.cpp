// P5911 [POI 2004] PRZ
// https://www.luogu.com.cn/problem/P5911  (1000 ms, 128 MB)
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
  int W,n;
  cin >> W >> n;
  
  const int S = 1 << n;
  vi ts(S), ws(S);
  for(int j = 0; j < n; ++j){
    int t,w;
    cin >> t >> w;
    for(int s = 0; s < S; ++s){
      if(s & (1 << j)){
        ts[s] = max(t,ts[s]);
        ws[s] += w;
      }
    }
  }

  vi dp(S,INT_MAX);
  for(int s = 0; s < S; ++s){
    if(ws[s] <= W) dp[s] = ts[s];
    for(int j = s; j > 0; j = s & (j-1))
      if(ws[j ^ s] <= W) dp[s] = min(dp[s], dp[j] + ts[j^s]);
  }
  cout << dp[S-1] << endl;

}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int T = 1;
  while (T--) solve();
  return 0;
}
