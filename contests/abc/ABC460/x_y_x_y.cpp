#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
#define fi first 
#define se second
using ll = long long;
using i128 = __int128_t;
using vi = vector<int>;

const int MOD = 998244353;

// ll vp(ll n, ll b){
//   ll cnt = 0;
//   while(n % b == 0){n /= b; cnt++;}
//   return cnt;
// }

ll mul(ll a, ll b){
  return (i128)((a % MOD) * (b % MOD)) % MOD;
}

// ll binexp(ll a, ll b){
//   ll ans = 1;
//   while(b){
//     if(b & 1) ans = mul(ans,a);
//     b >>= 1;
//     a = mul(a,a);
//   }
//   return ans; 
// }


ll f(ll n, ll m) {
  ll ans = 0;
  
  for (i128 low = 1; low <= n; low *= 10) {
    i128 pow = low * 10;

    ll r = (ll)((pow - 1) % m);
    ll d = m / gcd(m, r);

    ll cntX = n / d;

    ll up = (ll)min((i128)n, pow - 1);
    ll cntY = up - (ll)low+ 1;

    ans = (ans + mul(cntX,cntY)) % MOD;
  }

  return ans;
}


void solve(){
  ll N,M;
  cin >> N >> M;
  cout << f(N,M) << '\n';
}


int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int T;
  cin >> T;
  while(T--) solve();

  return 0;
}