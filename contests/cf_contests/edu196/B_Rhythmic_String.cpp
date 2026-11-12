#include<bits/stdc++.h>
using namespace std;
using ll = long long;


void solve(){
  int n;
  cin >> n;
  unordered_map<ll,ll> cnt; 
  vector<ll> a(n);
  for(int i = 0; i < n; ++i) cin >> a[i];
  sort(a.begin(),a.end());
  for(int i = 0; i < n; ++i){
    ll x = a[i]; 
    cnt[x]++;
    for(auto &[k,v] : cnt){
      if(k != x && x % k == 0) v++;
    }
  }
  ll ans = LLONG_MIN;
  for(auto &[k,v]:cnt){
    ans = max(ans,v);
  }
  ans = n - ans;
  cout << ans << '\n';
 }



int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);   

  int T;
  cin >>T;
  while(T--)solve();

  return 0;
}