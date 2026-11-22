// 456
// https://atcoder.jp/contests/abc456/tasks/abc456_b  (2000 ms, 1024 MB)
#include <bits/stdc++.h>
#include <iomanip>
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
  vector<vi> d(3,vector<int>(3));
  for(int j = 0; j < 3; ++j){
    for(int i = 0; i < 6; ++i){
      int x; cin >> x; 
      if(x >= 4 && x <= 6){
        d[j][x-4]++;
      }
    }
  }

  double ans = 0.0;
  for(auto a:{0,1,2}){
    for(auto b:{0,1,2}){
      for(auto c:{0,1,2}){
        if(a != b && b != c && a != c) ans += (double) d[0][a]/6 * (double) d[1][b]/6  * (double) d[2][c] / 6;
      }
    }
  }

  cout << ans << endl;

}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(10) << fixed;
  int T = 1;
  while (T--) solve();
  return 0;
}
