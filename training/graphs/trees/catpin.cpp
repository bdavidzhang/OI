//cat & pinguin
#include<bits/stdc++.h>

using namespace std;

void BFS(int n, vector<list<int>> &grid, vector<bool> &visited, vector<int> &dist, int d){
    if(visited[n]) return;
    dist[n] = d;
    visited[n] = true;
    queue<int> cur;
    cur.push(n);
    
    //cout << n << endl;
    for(auto x : grid[n]){
        if(!visited[x]){
            BFS(x, grid, visited, dist, d+1);
        } 
    }  


}



int main(){
    int n, d;
    cin >> n >> d;
    vector<list<int>> grid(n+1);
    for(int i = 0;i < n-1; ++i){
        int a,b;
        cin >> a >> b;
        grid[a].push_back(b); 
        grid[b].push_back(a); 
    }

    vector<int> dist(n+1);
    vector<bool> visited(n+1,false);
    BFS(1, grid, visited, dist, 0);

    //for(int i = 1; i <= n; ++i){
    //    cout << dist[i] << " "; 
    //}
    //cout << endl;

    long long cnt = 0;
    for(int i = 2; i <= n; ++i){
        if(dist[i] <= d){
            cnt++; 
        } 
    }

    cout << cnt << endl;
    return 0;
}

