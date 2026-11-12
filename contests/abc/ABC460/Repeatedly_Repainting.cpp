#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
#define fi first 
#define se second
using ll = long long;
using vi = vector<int>;


void solve(){
  int H,W;
  cin >> H >> W;  

  vector<string> S(H);
  for (auto &row : S) cin >> row;

  vector<vector<int>> dist(H, vector<int>(W, -1));
  queue<pair<int, int>> q;

  for (int i = 0; i < H; ++i) {
    for (int j = 0; j < W; ++j) {
      if (S[i][j] == '#') continue;

      bool hasBlack = false;
      for (int dx = -1; dx <= 1; ++dx) {
          for (int dy = -1; dy <= 1; ++dy) {
            if (dx == 0 && dy == 0) continue;

            int x = i + dx, y = j + dy;
            if (x < 0 || x >= H || y < 0 || y >= W) continue;

            if (S[x][y] == '#') hasBlack = true;
          }
      }

      if (hasBlack) {
          dist[i][j] = 0;
          q.push({i, j});
      }
    }
  }

  while (!q.empty()) {
    auto [i, j] = q.front();
    q.pop();

    for (int dx = -1; dx <= 1; ++dx) {
      for (int dy = -1; dy <= 1; ++dy) {
        if (dx == 0 && dy == 0) continue;

        int x = i + dx, y = j + dy;
        if (x < 0 || x >= H || y < 0 || y >= W) continue;
        if (dist[x][y] != -1) continue;

        dist[x][y] = dist[i][j] + 1;
        q.push({x, y});
      }
    }
  }

  for (int i = 0; i < H; ++i) {
    for (int j = 0; j < W; ++j) {
      cout << (dist[i][j] != -1 && dist[i][j] % 2 == 1 ? '#' : '.');
    }
    cout << '\n';
  }

}


int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  solve();

  return 0;
}