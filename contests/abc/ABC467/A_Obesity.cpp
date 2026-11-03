// A - Obesity
// https://atcoder.jp/contests/abc467/tasks/abc467_a  (2000 ms, 1024 MB)
#include <bits/stdc++.h>
using namespace std;


void solve(){
  long long H, W;
  cin >> H >> W;
  if(100 * 100 * W >= H * H * 25) cout << "Yes" << endl;
  else cout << "No" << endl;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int T = 1;
  //cin >> T;
  while(T--) solve();

}
