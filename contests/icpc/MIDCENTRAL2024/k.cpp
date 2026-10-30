#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;
#define int long long
using ll = long long;

const ll NINF = -1e18;
  int w,h,n;
ll v[55]; 
int st[55];

void solve( int w , int h , int a , int b ) {
  for( int i = n - 1 ; i >= 0 ; -- i ) {
    int x = ( 1ll << i );
    if( a >= x || b >= x ) {
      int cx = a / x , cy = b / x;
      int lx = x * cx , ly = x * cy;
      a -= lx , b -= ly;
      st[i] += cx * ( h / x ) + cy * ( w / x ) - cx * cy;
      // cout << cx << ' ' << cy << ' ' << st[i] << endl;
    }
  }
}

signed main () {
  cin >> w >> h >> n;
  for(int i = 0; i < n; ++i){
    cin >> v[i];
  }
  solve( w , h , w , h );
  int ans = 0;
  for( int i = n - 1 ; i >= 0 ; -- i ) {
    if( st[i] >= ( 1ll << 52 ) ) {
      ans = -1; break;
    }
    if( v[i] >= st[i] ) {
      ans += st[i] , st[i] = 0;
    } else {
      ans += v[i];
      st[i - 1] += ( st[i] - v[i] ) * 4;
    }
  }
  if( st[0] ) ans = -1;
  cout << ans << endl;
  return 0; 
}