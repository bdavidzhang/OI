#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using db = double;
using vll = vector<long long>;  
#define all(v) ((v).begin()), ((v).end())
#define sz(v) ((int)((v).size()))
#define fi first 
#define se second
#define pb push_back

const ll MOD = 998244353;

//----NT---
ll mul(ll a, ll b, ll p){
  a %= p;
  if (a < 0) a += p;
  b %= p;
  if (b < 0) b += p;
  return (__int128) a * b % p;
}
ll qpow(ll a,ll b, ll p = MOD){
  ll r = 1 % p;
  a %= p;
  if(a < 0) a += p;
  while(b){
    if(b&1) r = mul(r,a,p);
    a = mul(a,a,p);
    b >>=1;
  }
  return r; 
}

ll comb_mod;
vll fac, ifac;
void init_comb(int n, ll p = MOD){
  comb_mod = p;
  fac.assign(n+1,1);
  ifac.assign(n+1,1);
  for(int i = 1; i <= n; ++i)fac[i] = fac[i-1] * i % p;
  ifac[n] = qpow(fac[n],p-2,p);
  for(int i = n; i >= 1; --i) ifac[i-1] = ifac[i] * i % p;

}
ll C(int n, int k){
  if(k < 0 || k > n)return 0;
  return fac[n] * ifac[k] % comb_mod * ifac[n-k] % comb_mod;
} 
ll lucas(ll n, ll k){
  if(k==0) return 1;
  return C(n % comb_mod, k % comb_mod )* lucas(n / comb_mod, k / comb_mod) % comb_mod; 
}

vi pri, mnp;
void sieve(int n){
  pri.clear();
  mnp.assign(n+1,0);
  for(int i = 2; i <=n; ++i){
    if(!mnp[i]){
      pri.pb(i);
      mnp[i] = i;
    }
    for(int p : pri){
      if(1LL * i * p > n)break;
      int x = i * p;
      mnp[x] = p;
      if(i % p == 0){
        break;
      }
    }
  }
}
ll exgcd(ll a, ll b, ll &x, ll &y){
  if (b == 0){x = 1; y = 0; return a;}
  ll g = exgcd(b, a % b, y , x );
  y -= a / b * x;
  return g;

}
ll inv(ll a, ll p){
  a %= p;
  if (a < 0) a += p;
  ll x,y;
  if(exgcd(a,p,x,y) != 1) return -1;
  x %= p;
  if(x<0)x += p;
  return x;
}
vll iv;
void init_inv(int n, int p){
iv.assign(n+1,0); iv[1] = 1;
  for(int i = 2; i <= n; ++i) iv[i] = (p - p / i) * iv[p % i ] % p;
}

bool mergeCRT(ll &a, ll &m, ll b, ll n){
  b %= n;
  if (b < 0) b += n;
  ll x,y,g = exgcd(m,n,x,y);
  ll d = b -a;
  if (d % g != 0) return false;
  ll k = mul(x, d/g, n/g);
  ll mod = (ll)((__int128)m * (n/g));
  a = ((__int128)m * k + a) % mod; 
  m = mod; 
  return true;
}
ll excrt(vll &a, vll & m){
  ll r = 0, mod = 1;
  for(int i = 0;i < sz(a); ++i){
    if(!mergeCRT(r, mod, a[i], m[i]))return -1;   
  }
  return r;
}
//----NT---
//-------LA--------
const int K = 2;
struct Mat{
  ll a[K][K] = {};
  Mat operator*(const Mat &b)const {
    Mat r;
    for(int i = 0; i < K; ++i){
        for(int k = 0; k < K; ++k){
          if(!a[i][k])  continue;
          for(int j = 0; j < K; ++j) 
            r.a[i][j] = (r.a[i][j] + a[i][k] * b[a][j]) % MOD;
        
      }
    }
    return r;
  }
};

Mat qpow(Mat a, ll b){
  Mat r;
  for(int i = 0; i < K; ++i) r.a[i][i] = 1;
  while(b){
    if(b&1)r = r*a;
    a = a * a;
    b >>= 1;  
  }
  return r;
}

//-------LA--------


void solve(){
  int n;
  cin >> n;
  vll a(n),m(n);
  for(int i = 0 ;i < n; ++i) cin >> m[i] >> a[i];
  ll ans = excrt(a,m);
  cout << ans << '\n';
}


int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  solve();
  return 0;
}