#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
  int px,py,qx,qy,rx,ry,sx,sy;
  cin >> px >> py >> qx >> qy >> rx >> ry >> sx >> sy;
  __int128_t ux = px - qx, uy = py - qy, vx = rx - sx, vy = ry - sy;
  bool ok1 = ((ux * vy - vx * uy) != 0);
  bool ok2 = (ux*((px+qx)-(rx+sx)) + uy*((py+qy)-(ry+sy)) == 0);
  if(ok1 || ok2) cout << "Yes" << endl;
  else cout << "No" << endl;

}


signed main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
   
  int T;
  cin >>T ;
  while (T--) solve();

  return 0;
}