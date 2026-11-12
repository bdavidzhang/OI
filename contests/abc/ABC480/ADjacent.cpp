#include<bits/stdc++.h>
using namespace std;
#define endl '\n'

void solve(){
  vector<string> v(2);
  for(int i = 0;i < 2; ++i) cin >> v[i];
  for(int i = 0; i < 2; ++i)
  for(int j = 0; j < 2; ++j)
    if(v[i][j] == 'A'){
      if(v[i^1][j] == 'D' || v[i][j^1] == 'D'){
        cout << "Yes" << endl;
      }else{
        cout << "No" <<endl;
      }
    }

}


int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  
  solve();

  return 0;
}