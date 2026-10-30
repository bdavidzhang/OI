#pragma GCC optimize("O3")
#include<bits/stdc++.h>
using namespace std;
#define fore(i, l, r) for(int i = int(l); i < int(r); i++)
#define ford(i, r, l) for(int i = int(r)-1; i >= l; i--)
#define IOS ios::sync_with_stdio(false); cin.tie(0)
#define ll long long
#define pb push_back
#define ld long double
#define vint vector<int>
#define vll vector<ll>
#define mp(a, b) make_pair(a, b)
#define pii pair<int, int>
#define pll pair<ll, ll>
#define fi first
#define se second
const int MOD = 1e9 + 7;
const int dx[4] = { 1,0,-1,0 }, dy[4] = { 0,1,0,-1 };


void lightbulb(int posX, int posY, vector<vector<char>>&grid) {
      for (int i = posX+1; i < grid.size(); i++) {
            if (grid[i][posY] == '.' || grid[i][posY] == 't') {
                  grid[i][posY] = 't';
            }
            else break;
      }
      for (int i = posX-1; i >= 0; i--) {
            if (grid[i][posY] == '.' || grid[i][posY] == 't') {
                  grid[i][posY] = 't';
            }
            else break;
      }
      for (int i = posY+1; i < grid.size(); i++) {
            if (grid[posX][i] == '.' || grid[posX][i] == 't') {
                  grid[posX][i] = 't';
            }
            else break;
      }
      for (int i = posY - 1; i >= 0; i--) {
            if (grid[posX][i] == '.' || grid[posX][i] == 't') {
                  grid[posX][i] = 't';
            }
            else break;
      }
}
int main()
{
      int n; cin >> n;
      vector<vector<char>> grid(n, vector<char>(n, 0));
      fore(i, 0, n) {
            fore(j, 0, n) {
                  char c; cin >> c;
                  grid[i][j] = c;
            }
      }
      for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                  if (grid[i][j] == '?') lightbulb(i, j, grid);
            }
      }
      for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                  if (grid[i][j] == '.') {
                        cout << 0;
                        return 0;
                  }
                  if (grid[i][j] - '0' >= 0 && grid[i][j] - '0' <= 4) {
                        int x = grid[i][j] - '0';
                        for (int k = 0; k < 4; k++) {
                              int posX = dx[k] + i; int posY = dy[k] + j;
                              if (posX < 0 || posX >= n || posY < 0 || posY >= n) continue;
                              if (grid[posX][posY] == '?') x--;
                        }
                        if (x != 0) {
                              cout << 0;
                              return 0;
                        }
                  }
            }
      }
      cout << 1;
}
