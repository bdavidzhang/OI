// G. Vasya and Maximum Profit
// https://codeforces.com/contest/1107/problem/G  (3500 ms, 256 MB)
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
  int n, a;
  cin >> n >> a;
  vi d(n), c(n);
  vi b(n-1);
  for(int i = 0; i < n; ++i){
    cin >> d[i] >> c[i];
    c[i] = a - c[i];
  }

  for(int i = 0; i < n-1; ++i) 
    b[i] = d[i+1] - d[i];

  vector<array<int,2>> ch(n - 1, {-1,-1});
  vi stk;

  for(int i = 0 ;i < n - 1; ++i){
    while(!stk.empty() && b[i] > b[stk.back()]){
      ch[stk.back()][1] = ch[i][0];
      ch[i][0] = stk.back();
      stk.pop_back();
    }

    stk.push_back(i);
  }


  while(sz(stk) > 1){
    int x = stk.back();
    stk.pop_back();
    ch[stk.back()][1] = x;
  }
  
  ll ans = 0;
  for(int i = 0; i < n; ++i){
    ans = max(ans, 1LL * c[i]);
  }

  auto dfs = [&](auto self, int x, int l, int r) -> array<ll, 3>{
    if(x == -1) return {c[l], c[l], c[l]};
    auto [a1,b1,c1] = self(self,ch[x][0], l, x);
    auto [a2,b2,c2] = self(self,ch[x][1], x+1, r);
    ans = max(ans, c1+b2 - 1LL * b[x] * b[x]);
    return {a1+a2, max(b1, a1+b2), max(c2, a2+c1)}; 
  };

  if(n > 1){
    dfs(dfs,stk[0],0,n-1);
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
