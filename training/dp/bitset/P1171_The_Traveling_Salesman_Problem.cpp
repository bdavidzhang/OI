// P1171 The Traveling Salesman Problem
// https://www.luogu.com.cn/problem/P1171?lang=en  (1000 ms, 512 MB)
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

constexpr int INF = INT_MAX / 2;

void solve() {
  int n; 
  cin >> n;
  vector g(n,vi(n));
  for(int i = 0; i < n; ++i)
    for(int j = 0; j < n; ++j)
      cin >> g[i][j];

  vector dp(1 << (n-1), vi(n, INF));
  
  auto dfs = [&](auto self, int st, int u){
    if(st == (1 << (n-1)) - 1) return g[u][0];
    if(dp[st][u] != INF) return dp[st][u];
    for(int v = 1; v < n; ++v){
      if(v == u) continue; 
      if(!((st >> (v - 1)) & 1)) dp[st][u] = min(dp[st][u], self(self,st | (1 << (v-1)), v) + g[u][v]);
    }
    return dp[st][u];
  };

  cout << dfs(dfs,0,0) << endl;
 // for(int i = 0; i < (1 << n); ++i) cout << dp[i] << " ";
 // cout << endl;

}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int T = 1;
  while (T--) solve();
  return 0;
}
