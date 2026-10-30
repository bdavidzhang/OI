#include <bits/stdc++.h>
using namespace std;

int n,m;

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

struct DSU {
    vector<int> parent, sz;
    DSU(int n) {
        parent.resize(n);
        sz.assign(n, 1);
        iota(parent.begin(), parent.end(), 0);
    }
    int find(int x) {
        if (parent[x] != x) parent[x] = find(parent[x]);
        return parent[x];
    }
    void unite(int a, int b) {
        a = find(a);
        b = find(b);
        if (a != b) {
            if (sz[a] < sz[b]) swap(a, b);
            parent[b] = a;
            sz[a] += sz[b];
        }
    }
};

bool valid(int x, int y){
    return 0 <= x && x < n && 0 <= y && y < m;
}

void solve(){
    cin >> n >> m;
    vector<vector<int> > grid(n, vector<int>(m));
    for(int i = 0;i < n; ++i)
        for(int j = 0; j < m; ++j)
            cin >> grid[i][j];
    int ans = 0;
    int N = n * m;
    DSU dsu(N);
    auto idx = [&](int y, int x){return y * m + x;};
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            if(grid[i][j] == 0) continue;
            //  for (int k = 0; k < 4; k++) {
            //         int ni = i + dy[k], nj = j + dx[k];
            //         if (ni >= 0 && ni < n && nj >= 0 && nj < m && grid[ni][nj] > 0) {
            //             dsu.unite(idx(i, j), idx(ni, nj));
            //         }
            for(int k = 0; k < 4; ++k){
                if(valid(i+dy[k],j+dx[k]) && grid[i+dy[k]][j+dx[k]] != 0) dsu.unite(idx(i,j),idx(i+dy[k],j+dx[k]));
            }
        
        }
    
    }

    unordered_map<int,int> memo;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            if(grid[i][j] > 0){
                int root = dsu.find(idx(i,j));
                memo[root] += grid[i][j];
                ans = max(ans,memo[root]);
            }
        }
    }

    // cout << dsu.find(idx(n-1,m-1)) << endl;
 
    cout << ans << endl;
}




int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}