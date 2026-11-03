// P1276 校门外的树（增强版）
// https://www.luogu.com.cn/problem/P1276  (1000 ms, 125 MB)
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

const int MAXN = 1e5+10;
ll org[MAXN<<2], sap[MAXN<<2];
bool tc[MAXN<<2], tp[MAXN<<2];
int A[MAXN];

void pu( int rt ) {
  org[rt] = org[rt << 1] + org[rt << 1 | 1];
  sap[rt] = sap[rt << 1] + sap[rt << 1 | 1];
}
void pt( int rt , int len , bool cut, bool plant ) {
  if(cut) org[rt] = 0, sap[rt] = 0, tc[rt] = 1, tp[rt] = 0;
  if(plant) sap[rt] = len - org[rt], tp[rt] = 1; 
}

void pd( int rt , int l , int r ) {
	if( !tc[rt] && !tp[rt] ) return;
	int m = l + r >> 1;
	pt( rt << 1 , m - l + 1 , tc[rt], tp[rt] ) , pt( rt << 1 | 1 , r - m , tc[rt], tp[rt] ); 
  tc[rt] = 0, tp[rt] = 0;
}
void build( int rt , int l , int r ) {
  tc[rt] = 0, tp[rt] = 0;
	if( l == r ) { org[rt] = A[l], sap[rt] = 0; return; }
	int m = l + r >> 1;
	build( rt << 1 , l , m ) , build( rt << 1 | 1 , m + 1 , r );
	pu( rt );
}
void upd( int rt , int l , int r , int L , int R , bool cut, bool plant ) {
	if( L <= l && r <= R ) { pt( rt , r - l + 1 , cut, plant ); return; }
	pd( rt , l , r );
	int m = l + r >> 1;
	if( L <= m ) upd( rt << 1 , l , m , L , R , cut, plant );
	if( R > m ) upd( rt << 1 | 1 , m + 1 , r , L , R , cut, plant );
	pu( rt );
}
ll que( int rt , int l , int r , int L , int R ) {
	if( L <= l && r <= R ) return sap[rt];
	pd( rt , l , r );
	int m = l + r >> 1; ll re = 0;
	if( L <= m ) re += que( rt << 1 , l , m , L , R );
	if( R > m ) re += que( rt << 1 | 1 , m + 1 , r , L , R );
	return re;
}



void solve() {
  int n, q;
  cin >> n >> q;
  n++;
  for(int i = 1; i <= n; ++i)A[i] = 1;
  build(1,1,n);
  ll nsap = 0;
  while(q--){
    int t;
    cin >> t;
    int x,y;
    cin >> x >> y;
    x++; y++;
    if(t == 0){
      nsap += que(1,1,n,x,y);
      upd(1,1,n,x,y,1,0);
    }else{
      upd(1,1,n,x,y,0,1);
    }
  }
  cout << que(1,1,n,1,n) << '\n' << nsap << endl;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int TT = 1;
  while (TT--) solve();
  return 0;
}
