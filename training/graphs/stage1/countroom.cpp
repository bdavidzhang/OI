//counting rooms.cpp - CSES
#include<bits/stdc++.h>
using namespace std;

//idea: convert into a find connected components problem
//maintain a graph array
//maintain a "visited" bool array
//use DFS to search
//common movement techniques: dx, dy, isvalid determining function


int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};

bool isvalid(int x,int y, vector<string> &grid, int n, int m){
    if(x < 0 || y < 0) return false;
    if(x >= n || y >= m) return false;
    if(grid[x][y] == '#') return false;
    return true;
}

void DFS(int x, int y, vector<string> &grid, vector<vector<bool>> &vis, int n, int m){
    if(vis[x][y]) return;
    vis[x][y] = true;

    for(int i = 0; i < 4; ++i){
        if(isvalid(x+dx[i],y+dy[i],grid, n, m)){
            if(!vis[x+dx[i]][y+dy[i]]) DFS(x+dx[i],y+dy[i],grid,vis, n, m); 
        }
    }
}

int main(){

    int n, m;
    cin >> n >> m;
    vector<string> grid(n);
    vector<vector<bool>> vis(n,vector<bool>(m,false));
    for(auto & x : grid) cin >> x;
    long long ans = 0;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            if(isvalid(i,j, grid, n, m) && !vis[i][j]){
                DFS(i,j,grid, vis,n,m); 
                ans++;
            }
        }
    } 
        
   cout << ans << endl;
    return 0;
}

