#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<long long>;
using tiii = tuple<int,int,int>;
using vii = vector<vector<int>>;
using ld = long double;
using pii = pair<int,int>;
#define all(v) ((v).begin()),((v).end())
#define sz(v) ((int)((v).size()))
#define fi first
#define se second


const int MAXN = 1e3+10;
vector<string> g(MAXN);
int n,m;
pii ac,bc;
queue<pair<pii,pii>> q;
vector<vector<pii>> last(MAXN,vector<pii>(MAXN));
vector<vector<bool>> vis(MAXN,vector<bool>(MAXN));

int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};

bool valid(pii p){
    return p.fi >= 0 && p.fi < n && p.se >= 0 && p.se < m && g[p.fi][p.se] != '#';
}


string get(pii cur, pii next){
    if(next.fi-cur.fi == -1) return "U";
    if(next.fi-cur.fi == 1) return "D";
    if(next.se-cur.se == -1) return "L";
    if(next.se-cur.se == 1) return "R";
    return "BUG!";
}

void bfs(pii node){
    if(vis[node.fi][node.se]) return;
    vis[node.fi][node.se] = true;

    q.push(make_pair(node,make_pair(-1,-1)));
    while(!q.empty()){
        pair<pii,pii> cur = q.front();
        q.pop();
        for(int i = 0; i < 4; ++i){
            pii pt = make_pair(cur.fi.fi+dx[i],cur.fi.se+dy[i]);
            if(!vis[pt.fi][pt.se] && valid(pt)){
                q.push(make_pair(pt,cur.fi)); 
                vis[pt.fi][pt.se] = true;
            }
        }
        last[cur.fi.fi][cur.fi.se] = cur.se;
        if(cur.fi == bc) break;
    }
}


void solve(){
   cin >> n >> m;
   ac = make_pair(MAXN-2,MAXN-2);
   bc = make_pair(MAXN-2,MAXN-2);
   for(int i = 0; i < n; ++i){
       cin >> g[i];
       for (int j = 0; j < m; j++) {
           if(g[i][j] == 'A') ac = make_pair(i,j);
           if(g[i][j] == 'B') bc = make_pair(i,j);
       }
   }
   last[bc.fi][bc.se] = make_pair(-1,-1);
   bfs(ac);
   if(last[bc.fi][bc.se] == make_pair(-1,-1)){
       cout << "NO" << endl;
       return;
   }else{
       pii cur = bc;
       string ans = "";
       while(cur != ac){
           ans += get(last[cur.fi][cur.se],cur); 
           cur = last[cur.fi][cur.se];
        }
        reverse(all(ans));
        cout << "YES" << endl;
        cout << sz(ans) << endl;
        cout << ans << endl;
   }
}


int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    //cin >> t;
    for(int i = 0; i < t; ++i){
        solve();
    }
    return 0;
}
//then you will find joy in the LORD
//I will cause you to ride in triumph on
//the heights of the land
//and to feast on the inheritance of your father Jacob
