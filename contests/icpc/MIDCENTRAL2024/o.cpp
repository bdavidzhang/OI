#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=(a),i##end=(b); i <= i##end; ++ i)
using namespace std;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(0);
  int n;
  cin >> n;
  for(int i = 0; i < n; ++i){
    int x;
    cin >> x;
    cout << solve(x) << endl;
  }
}