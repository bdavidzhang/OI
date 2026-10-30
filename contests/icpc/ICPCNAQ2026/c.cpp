#include<bits/stdc++.h>
using namespace std;

const int MOD = 998244353;
long long fact[100001];




void solve(){
  int n;
  cin >> n;
  vector<pair<int,int>> vp(n);
  for(int i = 0;i < n; ++i){
    int a, b; cin >> a >> b;
    vp[i] = {min(a,b),max(a,b)};
  }
  auto key = [](const pair<int,int>& a, const pair<int,int>& b){
    if(a.first != b.first) return a.first > b.first; 
    return a.second > b.second;
  };
  sort(vp.begin(),vp.end(),key);

  vector<vector<long long>> dp(n,vector<long long>(2,0));
  bool div2 = vp[0].first == vp[0].second;
  if(div2){
    dp[0][0] = 1;
    dp[0][1] = 0;//...
  }else{
    dp[0][0] = 1;
    dp[0][1] = 1;
  }
  //0 is (min,max), 1 is (max,min)

  auto ori = [&](int i, int o){
    if (o == 0) return make_pair(vp[i].first,vp[i].second);
    return make_pair(vp[i].second,vp[i].first);
  }; //probably saved me 40 lines of code 


  for(int l = 1; l < n; ++l){
    vector<long long> cur = {0,0};
    for(int o = 0; o < 2; ++o){
      if(o == 1 && vp[l].first == vp[l].second) continue;
      auto [x,y] = ori(l,o);
      for (int p = 0; p < 2; ++p){
        auto [X,Y] = ori(l-1,p);
        if (x <= X && y <= Y){
          cur[o] = (cur[o] + dp[l-1][p] * ((X-x+1) % MOD) % MOD * ((Y-y+1) % MOD) ) % MOD; 
        }
      }
    }
    dp[l][0] = cur[0]; dp[l][1] = cur[1];
  }

  long long factor = 1;
  for(int i = 0; i < n;){ //:<
    int j = i;
    while(j < n && vp[j] == vp[i]) j++;
    factor = factor * fact[j-i] % MOD;
    i = j;
  }
  
  long long ans = (dp[n-1][0] + dp[n-1][1]) % MOD;
  ans = ans * (factor % MOD) % MOD;
  
  cout << ans << '\n';

  //the answer is (dp[n-1][0] + dp[n-1][1]) * sum factorial(over the number of groups)


}


int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  fact[0] = 1;
  for(int i = 1; i <= 100000; i++) fact[i] = i * fact[i-1] % MOD;

  int T;
  cin >> T;
  while(T--){
  solve();
  }
  return 0;
}