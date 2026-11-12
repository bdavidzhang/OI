#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define sz(x) ((int)(x).size())

void solve(){
  int n,m;
  cin >> n >> m;
  vector<string> names(n), votes(m);
  for(int i = 0 ; i < n; ++i){
    cin >> names[i];
  }
  
  for(int i = 0 ; i < m; ++i){
    cin >> votes[i];
  }
  
  unordered_map<int,int> ans; 
  for(int i = 0; i < m; ++i){
    int cnt = 0;
    bool match = false;
    int idx = -1;
    for(int j = 0; j < n; ++j){
      if(votes[i] == names[j]){
        match = true;
        idx = j;
        break;
      }else if(sz(votes[i]) == sz(names[j])){
        int m = 0;
        for(int k = 0; k < sz(votes[i]); ++k){
          if(votes[i][k] == names[j][k]) m++;
        }
        if(m == sz(votes[i]) - 1){
          cnt++;
          idx = j;
        }

      }
    }
    if(match || cnt == 1){
      if(idx != -1) ans[idx] = ans[idx] + 1;
    }
  }
  for(int i = 0;i < n; ++i) cout << ans[i] << endl;
}


int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  
  solve();

  return 0;
}