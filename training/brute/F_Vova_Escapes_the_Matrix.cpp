// F. Vova Escapes the Matrix
// https://codeforces.com/contest/1898/problem/F  (2000 ms, 256 MB)
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
#define endl '\n'

constexpr int dx[] = {-1,1,0,0};
constexpr int dy[] = {0,0,-1,1};



void solve() {
  int n,m;
  cin >> n >> m;
  vector<string> s(n);
  int vx = 0, vy = 0;
  int empty = 0;
  for(int i = 0; i< n; ++i){
    cin >> s[i];
    for(int j = 0; j < m; ++j){
      if(s[i][j] == 'V') vx = i, vy = j;
      if(s[i][j] == '.') empty += 1;
    }
  }
  int ans = empty;
  vector dis(n,vector(m,-1));
  queue<pii> q;
  q.emplace(vx,vy);
  dis[vx][vy] = 0;
  int cnt = 0;

  while(!q.empty()){
    auto [x,y] = q.front();
    q.pop();
    if(x == 0 || y == 0 || x == n-1 || y == m -1) cnt += 1;
    for(int k = 0; k < 4; ++k){
      int nx = x + dx[k];
      int ny = y + dy[k];
      if( 0 <= nx && nx < n && 0 <= ny && ny < m && dis[nx][ny] == -1 && s[nx][ny] != '#'){
        dis[nx][ny] = dis[x][y] + 1;
        q.emplace(nx,ny);
      }
    }
  }

  if(cnt == 0) ans = 0;
  else if (cnt == 1){
    for(int x = 0; x < n; ++x)
      for(int y = 0; y < m; ++y)
        if((x == 0 || y == 0 || x == n-1 || y == m-1) && dis[x][y] != -1) ans = min(ans,dis[x][y]);   
  }
  else{
    queue<array<int,4>> q;
    vector dise(n, vector(m,array{-1,-1}));
    vector ex(n, vector(m,array{-1,-1}));
    for(int x = 0; x < n; ++x)
      for(int y = 0; y < m; ++y) if((x == 0 || y == 0 || x == n-1 ||y == m-1) && s[x][y] != '#') q.push({x,y,0,x*m+y});

    while(!q.empty()){
      auto [x,y,d,e] = q.front();
      q.pop();
      if(dise[x][y][0] == -1){
        dise[x][y][0] = d;
        ex[x][y][0] = e;
      }else if(dise[x][y][1] == -1 && e != ex[x][y][0]){
        dise[x][y][1] = d;
        ex[x][y][1] = e;
      }else{
        continue;
      }

      for(int k = 0; k < 4; ++k){
        int nx = x + dx[k];
        int ny = y + dy[k];
        if(0 <= nx && nx < n && 0 <= ny && ny < m && s[nx][ny] != '#') q.push({nx,ny,d+1,e});
      }
    }

    for(int x = 0; x < n; ++x)
      for(int y = 0; y < m; ++y)
        if(dis[x][y] != -1 && dise[x][y][1] != -1) ans = min(ans,dis[x][y] + dise[x][y][0] + dise[x][y][1]) ;
  }
  ans = empty - ans;
  cout << ans << endl;

}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int T = 1;
  cin >> T;
  while (T--) solve();
  return 0;
}
