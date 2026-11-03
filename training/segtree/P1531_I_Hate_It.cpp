// P1531 I Hate It
// https://www.luogu.com.cn/problem/P1531  (1000 ms, 512 MB)
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

const int MAXN = 2e5+20;
ll A[MAXN];
ll T[MAXN << 2];
void pu( int rt ) { T[rt] = max(T[rt << 1] , T[rt << 1 | 1]); }

void build( int rt , int l , int r ) {
	if( l == r ) { T[rt] = A[l]; return; }
	int m = (l + r) >> 1;
	build( rt << 1 , l , m ) , build( rt << 1 | 1 , m + 1 , r );
	pu( rt );
}
void upd( int rt , int l , int r , int L , int R , ll c ) {
  if (l == r) { T[rt] = max(T[rt],c); return;}
	int m = (l + r) >> 1;
	if( L <= m ) upd( rt << 1 , l , m , L , R , c );
	if( R > m ) upd( rt << 1 | 1 , m + 1 , r , L , R , c );
	pu( rt );
}
ll que( int rt , int l , int r , int L , int R ) {
	if( L <= l && r <= R ) return T[rt];
	int m = (l + r) >> 1; ll re = LLONG_MIN;
	if( L <= m ) re = max(re,que( rt << 1 , l , m , L , R ));
	if( R > m ) re = max(re,que( rt << 1 | 1 , m + 1 , r , L , R ));
	return re;
}

void solve() {
  int n,q;
  cin >> n >> q;
  for(int i = 1; i <= n; ++i) cin >> A[i];
  build(1,1,n);
  while(q--){
    string s;
    cin >> s;
    int a,b;
    cin >> a >> b;
   // cout << s << '\n';
    if(s == "Q"){
      ll ans = que(1,1,n,a,b);
      cout << ans << '\n';
    }else if(s == "U"){
      upd(1,1,n,a,a,b);
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int TT = 1;
  //cin >> T;
  while (TT--) solve();
  return 0;
}
