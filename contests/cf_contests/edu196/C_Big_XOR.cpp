#include<bits/stdc++.h>
using namespace std;
using ll = long long;


void solve(){
  int n;
  cin >> n;
  ll k = 0,m=0;
  for(int i = 1; i <= n; ++i){
    k = k | i; m = m ^ i;
  }
  ll h = 0;
  vector<int> ans(n+1,0);
  while(n >= (1 << (h + 1))) h++;
  for(int j = h; j >= 0; --j){
    if((m & (1 << (j+1))) == 0){
      // cout << "yes" << endl;
      ans[1 << j] = 1;
      m ^= (1LL) << j;
      m ^= (1LL) << (j+1);
      }
  }
  // cout << ans << endl;
  for(int j = 1; j <= n; ++j){
    cout << ans[j] << " ";
  }
  cout << '\n';
  
 }



int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);   

  int T;
  cin >>T;
  while(T--)solve();

  return 0;
}