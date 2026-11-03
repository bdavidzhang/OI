// P3373 【模板】线段树 2
// https://www.luogu.com.cn/problem/P3373  (1000 ms, 125 MB)
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MAXN = 1e5+10;
ll A[MAXN], MOD;

ll T[MAXN << 2] , mu[MAXN << 2], ad[MAXN << 2];

//pull up
void pu( int rt ) { T[rt] = (T[rt << 1] + T[rt << 1 | 1])% MOD; }

//update point
void pt( int rt , int len , ll m, ll a ) {
  T[rt] = (T[rt] * m + a * len) % MOD;
  mu[rt] = mu[rt] * m % MOD;
  ad[rt] = (ad[rt] * m + a) % MOD;
}


//pull down
void pd( int rt , int l , int r ) {
	if( mu[rt] == 1 && ad[rt] == 0 ) return;
	int m = (l + r) >> 1;
	pt( rt << 1 , m - l + 1 , mu[rt], ad[rt] );
  pt( rt << 1 | 1 , r - m , mu[rt], ad[rt] );
  mu[rt] = 1, ad[rt] = 0; //identity tag
}


void build( int rt , int l , int r ) {
  mu[rt] = 1, ad[rt] = 0;
	if( l == r ) { T[rt] = A[l] % MOD; return; }
	int m = (l + r) >> 1;
	build( rt << 1 , l , m ) , build( rt << 1 | 1 , m + 1 , r );
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
	int m = (l + r) >> 1; ll re = 0;
	if( L <= m ) re += que( rt << 1 , l , m , L , R );
	if( R > m ) re += que( rt << 1 | 1 , m + 1 , r , L , R );
	return re % MOD;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n,q;
  cin >> n >> q >> MOD;
  for(int i = 1; i <= n; ++i) cin >> A[i];
  build(1,1,n);
  for(int i = 0; i < q; ++i){
    int t;
    cin >> t;
    if(t == 1){
      ll x,y,M;
      cin >> x >> y >> M;
      upd(1,1,n,x,y,M % MOD,0);
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

  return 0;
}
