#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  int ans = 0;
  for(int i = 0; i < n; ++i){
    int a,b; string s;
    cin >> a >> b >> s;
    if(s == "keep") ans += b - a;
  }
  cout << ans << endl;
  return 0;
}