// B - Deconstruct Chocolate
// https://atcoder.jp/contests/abc449/tasks/abc449_b  (2000 ms, 1024 MB)
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
  int H,W;
  cin >> H >> W;
  int q;
  cin >> q;

  while(q--){
    int t;
    cin >> t;
    int X;
    cin >> X;
    if(t == 1){
      cout << X * W << '\n';
      H = H - X;
    }else{
      cout << X * H << '\n';
      W = W - X;
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int T = 1;
  while (T--) solve();
  return 0;
}
