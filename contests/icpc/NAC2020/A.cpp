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




int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  
  int m, k; 
  cin >> m >> k;

  vi mu(k+1),ps;
  vector<bool> cs(k+1,false);

  mu[1] = 1;
  for(int i = 2; i <= k; ++i){
    if(!cs[i]){
      ps.pb(i);
      mu[i] = -1;
    }

    for(auto & p : ps){
      if(1LL * p * i > k) break;

      int x = i * p;
      cs[x] = true;

      if(i % p == 0){
        mu[x] = 0;
        break;
      }

      mu[x] = -mu[i];
    }
  }

  ll ans = 1;
  for(int d = 1; d <= k; ++d){
    if(mu[d] == 0) continue;

    ll tmp = power(2 * (k / d) + 1, m) - 1;
    ans = (ans + mu[d] * tmp + MOD) % MOD;
  }

  cout << ans << endl;



  return 0;
}
