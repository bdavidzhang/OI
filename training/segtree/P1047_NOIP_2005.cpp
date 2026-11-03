// P1047 [NOIP 2005 普及组] 校门外的树
// https://www.luogu.com.cn/problem/P1047  (1000 ms, 125 MB)
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


const int MAXN = 1e5 + 10;
ll T[MAXN << 2]; 
int tg[MAXN << 2];
bool A[MAXN];

void pu( int rt ) { T[rt] = T[rt << 1] + T[rt << 1 | 1]; }
void pt( int rt , int len , int c ) {
  T[rt] = (ll)c * len , tg[rt] = c;  //assign
}
void pd( int rt , int l , int r ) {
	if( tg[rt] == -1 ) return;
	int m = l + r >> 1;
	pt( rt << 1 , m - l + 1 , tg[rt] ) , pt( rt << 1 | 1 , r - m , tg[rt] ) , tg[rt] = -1;
}
void build( int rt , int l , int r ) {
	tg[rt] = -1;
	if( l == r ) { T[rt] = A[l]; return; }
	int m = l + r >> 1;
	build( rt << 1 , l , m ) , build( rt << 1 | 1 , m + 1 , r );
	pu( rt );
}
void upd( int rt , int l , int r , int L , int R , int c ) {
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

void solve() {
  int n,q;
  cin >> n >> q;
  n++;
  for(int i = 1; i <= n; ++i) A[i] = 1;
  build(1,1,n);
  while(q--){
    ll x,y;
    cin >> x >> y;
    upd(1,1,n,x+1,y+1,0);
  }
  ll ans = que(1,1,n,1,n);
  cout << ans << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int T = 1;
  //cin >> T;
  while (T--) solve();
  return 0;
}
