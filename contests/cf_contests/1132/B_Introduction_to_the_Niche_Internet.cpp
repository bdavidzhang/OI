#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
#define all(x) (x).begin(), (x).end()
#define int long long

void solve(){
  int n, k;
  cin >> n >> k;
  vi v(n);
  for(int i = 0; i < n; ++i) cin >>v[i];
  sort(all(v));

  ll tot = 0;
  vi res(n);
  int j = 0;
  for(int i = n - k; i < n; ++i){
    res[j] = v[i]; 
    j++;
    tot += v[i];
  }
  if(n == k){
    cout << "YES" << '\n';
    for(int a : res) cout << a << " ";
    cout << '\n';
    return;
  }
  if(v[n-k-1]*k >= tot){
    cout << "NO" << '\n';
  }else{
    for(int i = n - k - 1; i >= 0; --i){
      res[j] = v[i];
      j++;
    }
    cout << "YES" << '\n';
    for(int a : res) cout << a << " ";
    cout << '\n'; 
  }
}



signed main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int T;
  cin >>T ;
  while(T--)solve();


  return 0;
}

