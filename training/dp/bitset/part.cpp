//leetcode: can i win
// https://leetcode.com/problems/matchsticks-to-square/description/
#include<bits/stdc++.h>
using namespace std;

using ll = long long;
#define all(x) (x).begin(), (x).end()

void solve(){
  int n;
  cin >> n;
  vector<int> v(n);
  for(auto & x : v) cin >> x;
  
  int sum = accumulate(all(v),0);
  if(sum % 2){
    cout << "No" << endl;
    return;
  }
  
  int goal = sum / 2;
   vector<int> dp(1 << n, -1);


  auto dfs = [&](auto self, int st, int cur, int rest) -> bool{
    if(rest == 0) return st == (1 << n) - 1 ;

    if(dp[st] != -1) return dp[st];

    bool ans = 0;
    
    for(int i = 0; i < n; ++i){
      int tobe = cur + v[i];
      if(!((st << i) & 1) && tobe <= goal){
        int nst = st | (1 << i);
        if(tobe == goal) ans = self(self,nst,0,rest-1);
        if(tobe < goal) ans = self(self,nst,tobe,rest);

        if(ans ) break;
      }
    }

    dp[st] = ans;
    return ans;

  };

  bool ans = dfs(dfs,0,0,2);
  cout << (ans ? "Yes" : "No") << endl;
}



int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);


  solve();

  return 0;
}


