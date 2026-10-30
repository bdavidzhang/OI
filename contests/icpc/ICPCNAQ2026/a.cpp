#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MOD = 998244353;

ll binexp(ll a, ll p, ll MOD){
  ll ans = 1;
  while(p != 0){
    if(p % 2 == 1){
      ans = ans * a % MOD;
    }
    a = a * a % MOD;
    p /= 2;
  }
  return ans % MOD;
}

ll inv(ll k, ll MOD){
  return binexp(k,MOD-2,MOD);
}

void solve(){
  ll n;
  cin >> n;
  ll ans = 1;
  ans = ((n % MOD) * ((n+1) % MOD) % MOD) * ((n+2) % MOD) % MOD;
  ll inv6 = inv(6,MOD);
  ans = ans * inv6 % MOD;
  cout << ans << endl;
}

int main(){
  solve();

  return 0;
}


//proof by induction that 
//f(1) = 1
//f(2) = 2 + f(1) 
//f(3) = 3 + f(2) 
//f(n) = n + f(n-1)
//S(n) := f(1) + ... + f(n) 
//S(n) = n(n-1)/2 + S(n-1) 
//-> S(n) = n(n+1)(n+2) / 6 tetrahedral nums