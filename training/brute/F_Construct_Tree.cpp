// F. Construct Tree
// https://codeforces.com/contest/1917/problem/F  (2000 ms, 256 MB)
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

constexpr int N = 2001;

void solve() {
  int n,d;
  cin >> n >> d;
  vi l(n);
  for(int i = 0; i < n; ++i) cin >> l[i];
  sort(all(l));
  vector<bitset<N>> suf(n+1);

  suf[n].set(0);
  for(int i = n - 1;i >= 0; --i){
    suf[i] = suf[i+1] | suf[i+1] << l[i];
  }

  int sum = accumulate(all(l), 0);
  if(sum == d){
    cout << "Yes" << endl;
    return;
  }
  vector<bitset<N>> dp(d+1);
  dp[0].set(0);
  
  for(int i = 0 ;i < n; ++i){
    for(int j = d; j >= 0; j--){
      dp[j] |= dp[j] << l[i];
      if(j >= l[i]) dp[j] |= dp[j-l[i]];
    }
    sum -= l[i];
    if(sum <= d){
      for(int x = 0 ; x < d - sum; ++x){
        int y = d - sum - x;
        if(dp[x][y]){
          int j = 0;
          if(x < l[i]){
            j = suf[i+1]._Find_next(l[i] - x - 1);
            if(j == N) continue;
          }

          if(y + sum - j >= l[i]){
            cout << "Yes" << endl;
            return;
          }
        }
      }
    }
  }
  cout << "No" << endl;




}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int T = 1;
  cin >> T;
  while (T--) solve();
  return 0;
}
