#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define int long long
#define sz(x) ((int)(x).size())

void solve(){
  int n,k,t; 
  cin >> n >> k >> t;
  vector<int> v(n+2);
  bool has0 = false;
  for(int i = 1; i <= n; ++i){
    cin>> v[i];
    if(v[i] == 0) has0 = true;
  }
  v[0] = 0;
  v[n+1] = t;
  v.erase(unique(all(v)),v.end());
  sort(all(v));
  int N = sz(v);
  // for(auto x : v) cout << x << " ";
  // cout << endl;
  int ans = 0;
  
  for(int i = 0; i < N-1; ++i){
    if(v[i] == t) break;
    if(v[i] == 0 && !has0){
      ans += (v[i+1] - v[i] + k - 1) / k;
    }else{
      int x = (v[i+1] - v[i] + k - 1) / k - 1;
      ans += (x >= 0) ? x : 0; 
    }
  }
  cout << ans << endl;

}


signed main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  
  solve();

  return 0;
}