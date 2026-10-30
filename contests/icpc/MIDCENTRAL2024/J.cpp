#include <iostream>
#define rep(i,a,b) for(int i=(a),i##end=(b); i <= i##end; ++ i)
using namespace std;

int C[2006][2006];
void solve() {
  int n , k;
  cin >> n >> k;
  int ans = 0;
  rep( i , 0 , n ) {
      C[i][0] = 1 % k;
      rep( j , 1 , i ) {
        C[i][j] = ( C[i - 1][j - 1] + C[i - 1][j] ) % k;
        if( C[i][j] == 0 ) ++ ans;
      }
      if( C[i][0] == 0 ) ++ ans;
  }
  cout << ans << endl;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(0);
  int T = 1;
  // cin >> T; 
  while( T-- ) solve();
}