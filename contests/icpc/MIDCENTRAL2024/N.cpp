#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
#define rep(i,a,b) for(int i=(a),i##end=(b); i <= i##end; ++ i)
using namespace std;
const int N = 4e5 + 20;
#define int long long
int n , s;

void chk( int &cl , int &cr , int l , int r ) {
  if( cl == -1 || cr == -1 ) {
    cl = l , cr = r; return;
  }
  if( cl > cr ) {
    cl = max( cl , l ) , cr = min( cr , r );
  } else {
    cl = min( cl , l );
    cr = max( cr , r );
  }
}

int A[12];
void solve() {
  cin >> n >> s;
  int rs = s , ls = s;
  int leftl = -1 , leftr = -1 , rightl = -1 , rightr = -1;
  int crleftl = -1 , crleftr = -1;
  int crrightl = -1 , crrightr = -1;
  rep( i , 1 , n ) {
    int l , r;
    cin >> l >> r;
    if( l >= s && r > s && r > l ) rs = max( rs , r );
    if( l <= s && r < s && l > r ) ls = min( ls , l );
    if( l > s && r >= s && r < l ) chk( leftl , leftr , l , r );
    if( l < s && r <= s && r > l ) chk( rightl , rightr , l , r );
    if( l < s && r > s ) chk( crrightl , crrightr , l , r );
    if( l > s && r < s ) chk( crleftl , crleftr , l , r );
  }
  // cout << crrightl << ' ' << crrightr << endl;
  vector<pair<int,int>> vec;
  vector<int> ps;
  auto adsg = [&]( int l , int r ) {
    if( l == -1 || r == -1 ) return;
    // cout << l << ' ' << r << endl;
    vec.push_back( make_pair( l , r ) );
    ps.push_back( l );
    ps.push_back( r );
  };
  adsg( s , rs );
  adsg( s , ls );
  adsg( leftl , leftr );
  adsg( rightl , rightr );
  adsg( crleftl , crleftr );
  adsg( crrightl , crrightr );
  sort( ps.begin( ) , ps.end() );
  ps.erase( unique(ps.begin() , ps.end()) , ps.end() );
  int sz = ps.size();
  rep( i , 0 , ps.size() - 1 ) A[i] = i;
  int res = 1e18;
  // cout << ps[0] << ' ' << ps[1] << endl;
  // cout << crrightl << ' ' << crrightr << endl;
  do {
    int ans = 0;
    vector<int> od( 1 , s );
    for( int i = 0 ; i < sz ; ++ i ) {
      int x = ps[A[i]];
      od.push_back( x );
    }
    int lsd = -1 , ls = s , st = s;
    vector<pair<int,int>> wlk;

    // for( int x : od ) {
    //   cout << x << ' ';
    // } cout << endl;

    for( int x : od ) {
      int dir = ( x > ls ) + 1;
      if( x == ls ) dir = lsd;
      if( ( lsd & dir ) ) {
        ls = x , lsd = dir;
      }
      else {
        wlk.push_back( make_pair( st , ls ) );
        ans += abs( ls - st );
        st = ls;
        ls = x;
        lsd = dir;
      }
    }
    wlk.push_back( make_pair( st , ls ) );
    // for( auto& [l , r ] : wlk ) {
    //   cout << "walked " << l << ' ' << r << endl;
    // } cout << endl;
    ans += abs( ls - st );
    vector<int> ok( vec.size() );
    rep( i , 0 , vec.size() - 1 ) {
      int l = vec[i].first , r = vec[i].second;
      for( auto& [ L , R ] : wlk ) {
        if( L <= R && l <= r ) {
          if( L <= l && R >= r ) { ok[i] = 1; break; }
        }
        if( L >= R && l >= r ) {
          if( L >= l && R <= r ) { ok[i] = 1; break; }
        }
      }
    }
    int ook = 1;
    for( int x : ok ) if( !x ) ook = 0;
    if( ook ) res = min( res , ans );
    if( ans == 894 ) {
      for( int x : od ) cout << x << ' '; cout << endl;
    }
  } while( next_permutation( A , A + sz ) );
  cout << res << endl;
}

signed main() {
  cin.tie(0);
  ios::sync_with_stdio(0);
  int T = 1;
  // cin >> T; 
  while( T-- ) solve();
}