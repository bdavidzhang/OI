#include <bits/stdc++.h>
using namespace std;

vector<int> dx = {1, 0, -1, 0};
vector<int> dy = {0, 1, 0, -1};

bool valid(int x, int y, int n, int m,vector<string> &g) {
    return x >= 0 && x < n && y >= 0 && y < m && g[x][y] != 'X' && !isalpha(g[x][y]);
}

void DFS(int x, int y, vector<string> &g, vector<vector<bool>> &vs, int &pts, int n, int m) {
    if (vs[x][y]) return;
    vs[x][y] = true;
    if (g[x][y] == '.') {
        pts++;
        g[x][y] = ' ';
    }    
    for (int i = 0; i < 4; ++i) {
        if(valid(x+dx[i],y+dy[i],n,m,g)) DFS(x + dx[i], y + dy[i], g, vs, pts, n, m);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m;
    cin >> n >> m;
    
    vector<string> g(n);
    vector<pair<int,int>> pos;

    cin.ignore();
    long long dots = 0;
    for (int i = 0; i < n; ++i) {
        string s;
        getline(cin, s);
        g[i] = s;

        for (int j = 0; j < m && j < g[i].length(); ++j) {
            if (g[i][j] != '.' && g[i][j] != 'X' && g[i][j] != ' ') {
                pos.push_back({i, j});
            }
            if (g[i][j] == '.') dots++;
        } 
    }


    long long cnt = 0;
    vector<vector<bool>> vs(n, vector<bool>(m, false));

    for (auto p : pos) {
        int pts = 0;
        DFS(p.first, p.second, g, vs, pts, n, m);
        if (pts > 0) {
            dots -= pts;
            cnt++; 
        }
    }
    
    
    cout << cnt << " " << dots << endl;
    return 0;
}
