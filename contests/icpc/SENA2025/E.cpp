#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define int long long

signed main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;
  vector<int> a(n);
  for(int i = 0; i< n ;++i) cin >> a[i];
  sort(all(a));
  // for(auto x : a) cout << x << " ";
  // cout << endl;
  int i = 0;
  int ans = 0;
  while(i < n){
    int d = a[i];
    int j = 0;
    while(i+j < n && a[i+j] == d)j++;
    // cout << j << endl;
    if(d % 2 == 0){
      int r = j / 2 + 1;
      int st = d / 2;
      st += r; 
      ans = max(ans,st);
    }else{
      int r = (j + 1) / 2;
      int st = max(d / 2, d - d/2);
      st += r; 
      ans = max(ans,st);
    }
    i = i + j;
  }
  cout << ans << endl;
  return 0;
}