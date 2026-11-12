#include<bits/stdc++.h>
using namespace std;
using ll = long long;


void solve(){
  int l,r;
  cin >> l >> r;
  ll ans = max(max(abs(l),abs(r)) - min(abs(l),abs(r)) - 1,0);
  cout << ans << endl;
}



int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);   

  int T;
  cin >>T;
  while(T--)solve();

  return 0;
}