//leetcode: can i win
// https://leetcode.com/problems/matchsticks-to-square/description/
#include<bits/stdc++.h>
using namespace std;

using ll = long long;
#define all(x) (x).begin(), (x).end()

void solve(){
  int n; cin >> n;
  vector<int> ls(n);
  for(auto & x : ls) cin >> x;

  int tot = accumulate(all(ls),0);      
  if(tot % 4){
    cout << "No" << endl;
    return;
  }

  int goal = tot / 4;
  vector<int> dp(1 << n, -1);

  auto dfs = [&](auto self, int st, int cur, int rest) -> bool{
    if(rest == 0) return st == (1 << n) - 1;
    if(dp[st] != -1) return dp[st];

    bool ans = false;
    for(int i = 0; i < n; ++i){
      if(!((st >> i) & 1) && ls[i] + cur <= goal){
        if(ls[i] + cur == goal) ans = self(self,st | 1 << i, 0, rest - 1); 
        else if(ls[i] + cur < goal) ans = self(self, st | 1 << i, ls[i] + cur, rest);
        if(ans) break;
      }
    }

    dp[st] = ans;
    return ans;
  };  
  

  bool ans = dfs(dfs,0,0,4);
  cout << (ans ? "Yes" : "No") << endl;
}



int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);


  solve();

  return 0;
}

