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
//----------------math----------------

void solve(){
  ll a,b,p;
  cin >> a >> b >> p;
  ll ans = qpow(a,b,p);
  cout << a << "^" << b << " mod " << p << "=" << ans << endl;
}


int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int T = 1;
  // cin >> T;
  while(T--){
    solve();
  }

  return 0;
}
