#include<bits/stdc++.h>
using namespace std;
#define endl '\n'

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int r,c;
  cin >> r >> c;
  if(c == 1){
    cout << 1 << endl;
  }else if(c == 2){
    if(r == 1) cout << 1 << endl;
    else if(r == 2) cout << 2 << endl;
    else cout << -1 << endl;
  }else{
    if(r == 1) cout << (c + 2) / 3 << endl;
    else if(r == 2) cout << c / 2 + 1 << endl;
    else cout << -1 << endl;
  }

  return 0;
}