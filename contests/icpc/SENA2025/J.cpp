#include<bits/stdc++.h>
using namespace std;
#define endl '\n'

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;
  int o = 0;
  vector<int> a(n);
  bool ok = false;
  for(int i =0 ;i < n; ++i){
    cin >> a[i];
    if(a[i] % 2 != 0)o++;
    if(a[i] != 5 && a[i] != 0) ok = true;
  }
  if(ok){
  if(o >= 1){
    cout << 1 << endl;
  }
  else cout << n << endl;
  }else cout << n << endl;

  return 0;
}