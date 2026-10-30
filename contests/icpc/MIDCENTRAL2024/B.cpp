#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
#define rep(i,a,b) for(int i=(a),i##end=(b); i <= i##end; ++ i)
using namespace std;
const int N = 4e5 + 20;
#define int long long
using ll = long long;
int n , s;
int A[55];



vector<int> lp , rp;
void init( ) {
  int m = n / 2;
  for( int s = 0 ; s < ( 1ll << m ) ; ++ s ) {
    int res = 0;
    for( int i = 1 ; i <= m ; ++ i ) if( s & ( 1ll << i - 1 ) ) {
      res += A[i];
    }
    // cout << res << endl;
    lp.push_back( res );
  }
  for( int s = 0 ; s < ( 1ll << n - m ) ; ++ s ) {
    int res = 0;
    rep( i , 1 , n - m ) if( s & ( 1ll << i - 1 ) ) {
      res += A[m + i];
    }
    // cout << s << ' ' << res << endl;
    rp.push_back( res );
  }
  sort( lp.begin() , lp.end() );
  sort( rp.begin() , rp.end() );
  // for( int x : lp ) cout << x << ' '; cout << endl;
}

int getit( int x ) {
  int r = rp.size() - 1;
  // for( int x : rp ) cout << x << ' '; cout << endl;
  int ans = 0;
  rep( i , 0 , lp.size() - 1 ) {
    while( r >= 0 && lp[i] + rp[r] > x ) -- r;
    // cout << i << ' ' << r << ' ' << rp[r] << endl;
    ans += r + 1;
  }
  return ans;
}

void solve() {
  cin >> n;
  rep( i , 1 , n ) cin >> A[i];
  init();
  // cout << getit( 15 ) << endl;
  // return;
  // for( int x : lp ) cout << x << ' '; cout << endl;
  // cout << getit( 7 ) << endl;
  ll l = 0, r = (1LL<<n) - 2;
  ll lzl = 0;
  
  while(l < r){
    ll mid = l + (r - l) / 2;
    ll x = getit(mid) - lzl;

    if(x > mid - l + 1){
      r = mid;  
    }else{
      lzl += x;
      l = mid + 1;
    }
  }
  cout << l << endl;
}

signed main() {
  cin.tie(0);
  ios::sync_with_stdio(0);
  int T = 1;
  // cin >> T; 
  while( T-- ) solve();
}