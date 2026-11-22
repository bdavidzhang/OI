#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using pii = pair<int,int>;
#define pb push_back
using i128 = __int128_t; 

constexpr ll MOD = 998244353; 

ll power(ll a, ll b, ll p = MOD){
  ll ans = 1;
  while(b){
    if(b & 1) ans = ((i128)ans * a)% p; 
    a = ((i128)a * a) % p;
    b >>= 1;
  }
  return ans;
}

void solve(){
   
  int n,m, p;
  cin >> n >> m >> p;

  int h = n / 2, w = m /2;

  if(n % 2 && m % 2){
    cout << 1 << endl;
    return;
  }

  if(n % 2){
    cout << power(w + 1, h, p) << endl;
    return;
  }

  if(m % 2){
    cout << power(h + 1, w ,p) << endl;
    return;
  }

  int N = 1 << h;

  vector dp(h+1, vi(N,1));
  vector ndp(h+1, vi(N));

  vector good(h+1, vector(N,vi(h+1)));

  for(int u = 0; u <= h; u++)
    for(int B = 0; B < N; B++)
      for(int t = 0; t <= h; t++){
        int C = B;

        if(t < u)
          for(int i = t + 1; i < u; ++i)
            if(!(B >> (i-1) & 1)) 
              C &= ~(1 << i);


        if(u < t)
          for(int i = u + 1; i < t; ++i)
            if(!(B >> i & 1))
              C &= ~(1 << (i-1)); 

        good[u][B][t] = C;
      }
      

  for(int j = 1; j < w; ++j){
      for(int t = 0; t <= h; ++t)
        for(int i = 0; i < h; ++i)
          for(int s = 0; s < N; ++s){
            if(s >> i & 1)
              dp[t][s] += dp[t][s ^ (1 << i)];

            dp[t][s] %= p;
          }

    for(int u = 0; u <= h; ++u){
      for(int B = 0; B < N; ++B){

        ll res = 0;

        for(int t = 0; t <= h; ++t)
          res += dp[t][good[u][B][t]];

        res %= p;
        ndp[u][B] = res;
      }
    }
    dp.swap(ndp);
  }
        
  ll ans = 0;
  for(int t = 0; t <= h; ++t)
    for(int s = 0; s < N; ++s){
      ans += dp[t][s];
      ans %= p;
    }
  cout << ans << endl;
  

}



int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  solve();
  return 0;
}

