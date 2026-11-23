//leetcode: can i win
//https://leetcode.com/problems/can-i-win/description/
#include<bits/stdc++.h>
using namespace std;

void solve(){
  int m, t; // max int, total goal 
  cin >> m >> t;

  vector<int> dp(1 << m,-1); 

  auto dfs = [&](auto self, int goal, int st) -> bool {
    if(goal <= 0) return false;
    if(dp[st] != -1) return dp[st];


    dp[st] = 0;
    for(int i = 0; i < m; ++i){
      if(!((st >> i) & 1)) dp[st] |= !self(self,goal - i - 1, st | (1 << i));
    }
    
    return dp[st];
  };  

  bool ans = dfs(dfs,t,0);
  cout << (ans ? "Yes" : "No") << endl;
}



int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);


  solve();

  return 0;
}
