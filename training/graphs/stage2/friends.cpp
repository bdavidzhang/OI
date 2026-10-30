#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<long long>;
using tiii = tuple<int,int,int>;
using vii = vector<vector<int>>;
using ld = long double;
using pii = pair<int,int>;
using vb = vector<bool>;
#define all(v) ((v).begin()),((v).end())
#define sz(v) ((int)((v).size()))
#define fi first
#define se second
#define mp make_pair
#define pb push_back

const int MAXN = 1e5+5;
vector<bool> vis(MAXN);
vector<vector<int>> g(MAXN);
queue<int> q;
stack<int> s;
vector<int> d;
int n,m;

vb color(MAXN);

void bfs(int node){
    if(vis[node]) return;
    vis[node] = true;

    q.push(node);
    color[node] = true;
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        for(auto x : g[cur]){
            if(!vis[x]){
                q.push(x);
                vis[x] = true;
                color[x] = !color[cur];
            }
        }
    }
}

void solve(){
    cin >> n>> m;
    for (int i = 0; i < m; i++) {
        int a,b;
        cin >> a >> b;
        g[a].pb(b);
        g[b].pb(a);
    }
    for(int i = 1; i<= n; ++i){
        bfs(i);
    }
    bool flag = true;
    for(int i = 1; i<= n; ++i){
        for(auto x: g[i]){
            if(color[x] == color[i]){
                flag = false;
                break;
            }
        }
    }
    if(flag){
        for(int i = 1; i <=n;++i){
            if(color[i]) cout << 1 << " ";
            else cout << 2 << " ";
        }
        cout << endl;
    }else{
        cout << "IMPOSSIBLE" << endl;
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
