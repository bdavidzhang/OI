#include<bits/stdc++.h>
using namespace std;
using vi = vector<int>; 
using ll = long long;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n,m;
  cin >> n >> m;
  vi A(n), B(n-1);
  for(int i = 0; i < n; ++i) cin >> A[i];
  for(int i = 0; i < n-1; ++i) cin >> B[i];
  ll ans = LLONG_MAX;
  for(int st = 0; st < 2; ++st){
    int cur = st;
    ll cnt = 0;
    for(int i = 0; i < n-1; ++i){
      cnt += !(A[i] == cur); 
      cur = cur ^ B[i];
    }
    cnt += !(A[n-1] == cur); 
    ans = min(ans, cnt);
  }
  
  cout << ans << endl;
  return 0;
}