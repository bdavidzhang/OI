//leetcode: can i win
//https://leetcode.com/problems/can-i-win/description/
#include<bits/stdc++.h>
using namespace std;

void solve(){
  int n, m;
  cin >> n >> m;

  vector<int> g(m+1,0);
  //assume we have g initialized; 
  
  for(int i = 0; i < n; ++i){
    for(auto &j : hats[i]){
      g[j] |= 1 << i;
    }
  }

  vector dp(1 << n, vector<int>(m+1,-1));

  auto dfs = [&](auto self, int st, int j){
    if(st == (1 << n) - 1) return 1;
    if(i == m+1) return 0;
    if(dp[st][j] != -1) return dp[st][j];
    
    int ans = self(self,st,j+1);
    int cur = g[j];

    int r;
    while(cur){
      r = cur & -cur; 
      if((st & r) == 0) ans = (ans + self(self,st | r, j+1)) % MOD;
      cur ^= r;
    }

    
    dp[st][j] = ans;
    return ans;
  };

  return dfs(dfs,0,0);

}



int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);


  solve();

  return 0;
}

