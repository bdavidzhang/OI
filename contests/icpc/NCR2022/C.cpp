//currenlty still a bit unfamiliar with implementing BFS/DFS ...
//Cookie 
#include<bits/stdc++.h>
using namespace std;

int n,m;

vector<pair<int ,int>> neighbor(int x, int y){
    vector<pair<int, int>> v;
    for(int dx = -1; dx <= 1; dx += 2){
        int dy = 0;
        if(x + dx < 0 || x + dx >= m || y + dy < 0 || y + dy >= n) continue;
        v.push_back({x+dx, y+dy});
    }
    for(int dy = -1; dy <= 1; dy += 2){
        int dx = 0;
        if(x + dx < 0 || x + dx >= m || y + dy < 0 || y + dy >= n) continue;
        v.push_back({x+dx, y+dy});
    }

    return v;

}


//we should do grid bfs instead
int main(){
    
    cin >> n >> m;
    
    vector<string> grid(n);
    

    for(int i = 0; i < n; ++i){
        cin >> grid[i];
    }

    vector<vector<int>> value(n, vector<int>(m, -1));
    queue<pair<int, int>> q;
    // vector<vector<bool>> visited(n, vector<bool>(m,0));

    for(int i = 0 ;i < n; ++i){
        for(int j =0 ; j < m; ++j){
            if(grid[i][j] == 'X'){
                if(i == 0 || i == n-1 || j == 0 || j == m-1){
                    value[i][j] = 1;
                    q.push({j, i});
                }
                else{
                    for(auto &p : neighbor(j,i)){
                        if(grid[p.second][p.first] == '-'){
                            value[i][j] = 1;
                            q.push({j, i});
                            break;
                        }
                    }
                }
            }
        }
    }

    while(!q.empty()){
        auto p = q.front();
        q.pop();
        int x = p.first;
        int y = p.second;
        // visited[y][x] = 1;

        for(auto& point: neighbor(x,y)){
            if(grid[point.second][point.first] == 'X' && value[point.second][point.first] == -1){
                value[point.second][point.first] = value[y][x] + 1;
                q.push(point);
            }
        }
        
    }


    int maxcnt = 1;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            maxcnt = max(maxcnt,value[i][j]);
            // cout << value[i][j];
        }
        // cout << endl;
    }

    cout << maxcnt << endl;

    return 0;
}