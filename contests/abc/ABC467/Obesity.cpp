#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int H,W;
  cin>> H >> W;
  if(100 * 100 * W >= 25 * H * H) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}