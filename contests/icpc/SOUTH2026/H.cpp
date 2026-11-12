#include<bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())

int n, deg[109][109]; 
string s[109];
bool vs[109][109];

int E, V;

void dfs(int x,int y) {
    if(vs[x][y]) return; 
    ++V;vs[x][y] = 1; 
    if(x < n && s[2*x+2][2*y] =='o')  {
        ++deg[x][y], ++deg[x+1][y];
        ++E; dfs(x+1,y);
    }  
    if(y < n && s[2*x][2*y +2] == 'o') {
        ++deg[x][y], ++ deg[x][y+1]; 
        ++E; dfs(x,y+1);
    }
}
queue<pair<int,int>>q;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
char get(int k) {
    if(k == 0) return '^';
    if(k == 1) return '<';
    if(k == 2) return 'v';
    if(k ==3) return '>';
}
signed main() {
    cin >> n;
    for(int i=1;i<=2*n+1;++i) cin>>s[i], s[i] = " "+s[i];
    for(int i=1;i<=n;++i)
        for(int j=1;j<=n;++j) 
            if(s[2*i][2*j] =='o' && !vs[i][j]) {
                E = V = 0;
                dfs(i,j); 
                if(E > V) {
                    cout << "impossible";
                    return 0;
                }
            } 
    for(int i=1;i<=n;++i)
        for(int j=1;j<=n;++j)
            if (deg[i][j] == 1) q.emplace(i,j);
    while(q.size()) {
        auto [x,y] = q.front(); q.pop();
        if(deg[x][y] == 0) continue; 
        for(int k=0;k<4;++k) {
            int nx=x + dx[k], ny = y + dy[k];
            if(nx < 1 || nx > n || ny < 1 || ny > n) continue;
            if(deg[nx][ny] >= 1) {
                s[2*x + dx[k]][2*y + dy[k]] = get(k);
                if(--deg[nx][ny] ==1) q.emplace(nx,ny);
            }
        }
    }

    for(int i=1;i<=n;++i)
        for(int j=1;j<=n;++j) 
            if(deg[i][j] > 1) {
                int x = i, y = j;
                for(int k =0; k < 4;++k) {
                    deg[x][y] = 0; 
                    s[2 * x + dx[k]] [2*y + dy[k]] = get(k);
                    x += dx[k], y += dy[k];
                }
            }
    for(int i=1;i<=2*n+1; ++i) cout << s[i] << endl; 
            
    return 0; 
}