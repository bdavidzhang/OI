#include<bits/stdc++.h>
#include <iterator>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<long long>;
using pii = pair<int,int>;
#define sz(x) ((int)(x).size())


int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;

  vector<string> grid(n);
  for(auto & r : grid) cin >> r;

  vector id(n, vi(m, -1));
  vector<pii> pos;

  for(int r = 0; r < n; ++r)
    for(int c = 0; c < m; ++c)
      if(grid[r][c] == 'V' || grid[r][c] =='H')
        id[r][c] = sz(pos), pos.emplace_back(r,c);

  int k = sz(pos);
  vector<vector<pii>> adj(k);
  vi forced(k,-1);

  constexpr int dr[] = {-1,0,1,0};
  constexpr int dc[] = {0,1,0,-1};

  auto has_face = [](char statue, int side) -> int {
    return (side % 2 == 0) == (statue == 'V');
  };

  for(int u = 0; u < k; ++u){
    auto [sr, sc] = pos[u];

    for(int side = 0; side < 4; ++side){
      int r = sr, c = sc, dir = side;
      int start_face = has_face(grid[sr][sc], side);

      while (true) {
        int nr = r + dr[dir];
        int nc = c + dc[dir];

        if(nr < 0 || nr >= n || nc < 0 || nc >= m){
          nr = r; 
          nc = c; 
          dir ^= 2;
        }

        r = nr;
        c = nc;

        char cell = grid[r][c];

        if(cell == '#'){
          if(forced[u] != -1 && forced[u] != start_face){
            cout << -1 << endl;
            return 0;
          }
          forced[u] = start_face;
          break;
        }

        int v = id[r][c];
        if(v != -1){
          int end_face = has_face(cell, dir^2);
          adj[u].emplace_back(v,start_face^end_face);
          break;
        }

        if(cell == '/') dir ^= 1;
        else if(cell == '\\') dir ^= 3;
      }
    }
  }

  vi val(k, -1);
  int ans = 0;

  for(int root = 0; root < k; ++root){
    if(val[root] != -1) continue;

    queue<int> q;
    q.push(root);
    val[root] = 0;

    int size = 0, ones = 0;
    bool valid[2] = {true, true};

    while(!q.empty()){
      int u = q.front(); q.pop();

      ++size;
      ones += val[u];

      if(forced[u] != -1){
        int flip = val[u] ^ forced[u];
        valid[flip ^ 1] = false;
      }

      for(auto [v,w] : adj[u]){
        int expected = val[u] ^ w;
        if(val[v] == -1){
          val[v] = expected;
          q.push(v);
        }else if(val[v] != expected){
          cout << -1 << endl;
          return 0;
        }
      }
    }
    
    if(!valid[0] && !valid[1]){
      cout << -1 << endl;
      return 0;
    }

    int keep = valid[0] ? ones : size + 1;
    int flip = valid[1] ? size - ones : size + 1;
    ans += min(keep,flip);

  }

  cout << ans << endl;

  return 0;
}


