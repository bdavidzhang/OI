// B - Keep the Change
// https://atcoder.jp/contests/abc467/tasks/abc467_b  (2000 ms, 1024 MB)
#include <bits/stdc++.h>
using namespace std;

void solve(){
  int N;
  cin >> N;
  long long ans = 0;
  for(int i =0 ; i < N; ++i){
    long long A,B;
    string s;
    cin >> A >> B;
    cin >> s;
    if (s == "keep") ans += (B - A);
  }
  cout << ans << endl;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int T = 1;
  while(T--)solve();
}
