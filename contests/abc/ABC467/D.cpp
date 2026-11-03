// D - Concentric Circles
// https://atcoder.jp/contests/abc467/tasks/abc467_d  (2000 ms, 1024 MB)
#include <bits/stdc++.h>
using namespace std;


void solve(){
   long long px,py,qx,qy,rx,ry,sx,sy;
  cin >> px >> py >> qx >> qy >> rx >> ry >> sx >> sy;
  __int128 ux = qx-px, uy = qy-py, vx = sx-rx, vy = sy-ry;
  bool ok = (ux*vy - uy*vx != 0) ||
            (ux*((px+qx)-(rx+sx)) + uy*((py+qy)-(ry+sy)) == 0);
  cout << (ok ? "Yes" : "No") << "\n";
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int T;
  cin >>T ;
  while(T--) solve(); 
}
