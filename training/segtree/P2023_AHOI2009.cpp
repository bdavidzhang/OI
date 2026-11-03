// P2023 [AHOI2009] 维护序列
// https://www.luogu.com.cn/problem/P2023  (1000 ms, 125 MB)
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vll = vector<ll>;
using vpii = vector<pii>;
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()

const int MAXN = 2e5 + 10;
ll T[MAXN << 2] , mu[MAXN << 2], ad[MAXN << 2];
ll A[MAXN], MOD; 


void pu( int rt ) { T[rt] = (T[rt << 1] + T[rt << 1 | 1]) % MOD; }

void pt( int rt , int len , ll m, ll a ) { 
  T[rt] = (T[rt] * m + a * len) % MOD;
  mu[rt] = (mu[rt] * m) % MOD;
  ad[rt] = (ad[rt] * m + a) % MOD;
}

void pd( int rt , int l , int r ) {
	if( mu[rt] == 1 && ad[rt] == 0 ) return;
	int mid = (l + r) >> 1;
	pt( rt << 1 , mid - l + 1 , mu[rt], ad[rt]) , pt( rt << 1 | 1 , r - mid , mu[rt], ad[rt] );
  mu[rt] = 1, ad[rt] = 0;
}

void build( int rt , int l , int r ) {
  mu[rt] = 1, ad[rt] = 0;
	if( l == r ) { T[rt] = A[l] % MOD; return; }
	int mid = (l + r) >> 1;
	build( rt << 1 , l , mid ) , build( rt << 1 | 1 , mid + 1 , r );
	pu( rt );
}

void upd( int rt , int l , int r , int L , int R , ll m, ll a ) {
	if( L <= l && r <= R ) { pt( rt , r - l + 1 , m, a ); return; }
	pd( rt , l , r );
	int mid = (l + r) >> 1;
	if( L <= mid ) upd( rt << 1 , l , mid , L , R , m, a );
	if( R > mid ) upd( rt << 1 | 1 , mid + 1 , r , L , R , m, a );
	pu( rt );
}

ll que( int rt , int l , int r , int L , int R ) {
	if( L <= l && r <= R ) return T[rt];
	pd( rt , l , r );
	int mid = (l + r) >> 1; ll re = 0;
	if( L <= mid ) re += que( rt << 1 , l , mid , L , R ) % MOD;
	if( R > mid ) re += que( rt << 1 | 1 , mid + 1 , r , L , R ) % MOD;
	return re % MOD;
}

void solve() {
  int n;
  cin >> n >> MOD; // could get RE bc not cin, or out of bounds
  for(int i = 1 ;i <= n; ++i) cin >> A[i];
  build(1,1,n);
  int q;
  cin >> q;
  while(q--){
    int t;
    cin >> t;
    if(t == 1){
      ll x,y,m;
      cin >> x >> y >> m;
      upd(1,1,n,x,y,m % MOD,0);
    }else if(t == 2){
      ll x,y,a;
      cin >> x >> y >> a;
      upd(1,1,n,x,y,1,a % MOD);
    }else{
      ll x,y;
      cin >> x >> y;
      ll ans = que(1,1,n,x,y);
      cout << ans << '\n';
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int T = 1;
//  cin >> T;
  while (T--) solve();
  return 0;
}
