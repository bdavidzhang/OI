// P3372 【模板】线段树 1
// https://www.luogu.com.cn/problem/P3372  (1000 ms, 512 MB)
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int MAXN = 2e5+10;
ll T[MAXN << 2] , tg[MAXN << 2];
ll A[MAXN];



void pu( int rt ) { T[rt] = T[rt << 1] + T[rt << 1 | 1]; }
void pt( int rt , int len , ll c ) { T[rt] += c * len , tg[rt] += c; }
void pd( int rt , int l , int r ) {
	if( !tg[rt] ) return;
	int m = l + r >> 1;
	pt( rt << 1 , m - l + 1 , tg[rt] ) , pt( rt << 1 | 1 , r - m , tg[rt] ) , tg[rt] = 0;
}
void build( int rt , int l , int r ) {
	tg[rt] = 0;
	if( l == r ) { T[rt] = A[l]; return; }
	int m = l + r >> 1;
	build( rt << 1 , l , m ) , build( rt << 1 | 1 , m + 1 , r );
	pu( rt );
}
void upd( int rt , int l , int r , int L , int R , ll c ) {
	if( L <= l && r <= R ) { pt( rt , r - l + 1 , c ); return; }
	pd( rt , l , r );
	int m = l + r >> 1;
	if( L <= m ) upd( rt << 1 , l , m , L , R , c );
	if( R > m ) upd( rt << 1 | 1 , m + 1 , r , L , R , c );
	pu( rt );
}
ll que( int rt , int l , int r , int L , int R ) {
	if( L <= l && r <= R ) return T[rt];
	pd( rt , l , r );
	int m = l + r >> 1; ll re = 0;
	if( L <= m ) re += que( rt << 1 , l , m , L , R );
	if( R > m ) re += que( rt << 1 | 1 , m + 1 , r , L , R );
	return re;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n,m;

  cin >> n >> m;
  for(int i = 1; i <= n; ++i){
    cin >> A[i];
  }
  build(1,1,n);
  for(int i = 0; i < m; ++i){
    int t;
    cin >> t;
    if(t== 1){
      int x,y;
      long long k;
      cin >> x >> y >> k;
      upd(1,1,n,x,y,k);
    }else{
      int x,y;
      cin >> x >> y;
      ll ans = que(1,1,n,x,y);
      cout << ans << '\n';
    }
  }

  return 0;
}
