#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using vii = vector<vector<int>>;
using vll = vector<long long>;
using db = double;
#define all(v) ((v).begin()), ((v).end())
#define sz(v) ((int)((v).size()))
#define fi first 
#define se second 
#define mp make_pair
#define pb push_back

const ll MOD = 998244353; 
const db eps = 1e-9;

//--------------math--------------

ll mul(ll a, ll b, ll p){
  a %= p; 
  if (a < 0) a += p;
  b %= p;
  if (b < 0) b += p;
  return (__int128)a * b % p;
}

ll qpow(ll a,ll b, ll p = MOD){
  ll r = 1 % p;
  a %= p;
  if (a < 0) a += p;
  while(b){
    if (b & 1) r = mul(r,a,p);
    a = mul(a,a,p);
    b >>= 1;
  }
  return r; 
}
ll combMod;
vll fac, ifac;
void initComb(int n, ll p = MOD){
  combMod = p;
  fac.assign(n+1, 1);
  ifac.assign(n+1,1);
  for(int i = 1; i <= n; ++i)fac[i] = fac[i-1] * i % p;
  ifac[n] = qpow(fac[n],p-2,p);
  for(int i = n; i >= 1; --i) ifac[i-1] = ifac[i] * i % p ;
}
ll C(int n, int k){
  if(k < 0 || k >  n)return 0;
  return fac[n] * ifac[k] % combMod * ifac[n-k] % combMod;
}
ll lucas(ll n, ll k){
  if(k==0) return 1;
  return C(n % combMod, k % combMod) * lucas(n / combMod, k / combMod) % combMod;
}

//----------------math----------------


void solve(){
  ll T, N;
  cin >> T >> N;
  initComb(N);
  ll ans = 0;
  for(int i = 0;i < T; ++i){
    ll n,m;
    cin >> n >> m;
    ans = ans ^ C(n,m);
  }
  cout << ans << endl;
}


int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  solve();

  return 0;
}
