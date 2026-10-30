#include<bits/stdc++.h>
using namespace std;


struct state{
    int a,b;
    int type;
};



int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);


    int n,a,b,c,d;
    cin >> n >> a >> b >> c >> d;

    vector<vector<vector<bool>>> visited(2,vector<vector<bool>>(n,vector<bool>(n,false)));

    queue<state> q;
    vector<pair<int,int>> moves_ab, moves_cd;
    int dx[4] = {1,1,-1,-1};
    int dy[4] = {1,-1,1,-1};

    for(int i = 0; i < 4; ++i){
        moves_ab.push_back({a*dx[i],b*dy[i]});;
        moves_ab.push_back({b*dx[i],a*dy[i]});;
        moves_cd.push_back({c*dx[i],d*dy[i]});;
        moves_cd.push_back({d*dx[i],c*dy[i]});;
    }
    vector<vector<pair<int,int>>> moves = {moves_ab,moves_cd};

    q.push({0,0,0});
    q.push({0,0,1});
    visited[0][0][0] = visited[1][0][0] = 1;
    
    while(!q.empty()){
        auto [r,c,t] = q.front();
        q.pop();
        int nt = 1-t;
        for (auto [dr,dc] : moves[t]){
            int nr = r + dr, nc = c +dc;
            if (0 <= nr && nr < n && 0 <= nc && nc < n && !visited[nt][nr][nc]){
                visited[nt][nr][nc] = true;
                q.push({nr,nc,nt});
            }
        }
    }

    long long cnt = 0;
    for(int r = 0; r < n; ++r)
        for(int c = 0; c < n; ++c)
            if(visited[0][r][c] || visited[1][r][c]) cnt++;
        
    cout << cnt << endl;

    return 0;
}