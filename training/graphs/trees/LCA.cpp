#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<long long>;
using tiii = tuple<int,int,int>;
using vii = vector<vector<int>>;


const int MAXN = 5e5+10;

vi lg(MAXN);;
vii g(MAXN);
vi depth(MAXN);
vii pa(MAXN,vi(22));
void dfs(int node, int par){
    pa[node][0] = par;
    depth[node] = depth[par]+1;
    for (int i = 1; i <= lg[depth[node]]; i++) {
       pa[node][i] = pa[pa[node][i-1]][i-1]; 
    }
    for (int x: g[node]) {
       if(x != par) dfs(x,node); 
    }

}

int LCA(int x, int y){
    if (depth[x] < depth[y]) swap(x,y);
    while(depth[x] > depth[y])
        x = pa[x][lg[depth[x]-depth[y]]-1];
    if(x == y) return x;
    for(int k = lg[depth[x]] - 1; k >= 0; --k){
        if(pa[x][k] != pa[y][k])
            x = pa[x][k], y = pa[y][k];
    }
    return pa[x][0];
}


int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m,s;
    cin >> n >> m >> s;

    for (int i = 0; i < n-1; i++) {
       int a,b;
       cin >> a >> b;
       g[a].push_back(b);
       g[b].push_back(a);
    }

    for(int i = 1; i <= n; ++i){
        lg[i] = lg[i-1] + (1 << lg[i-1] == i);
    }    
    dfs(s,0);
    for(int i = 0;i < m; ++i){
        int x,y;
        cin >> x >> y;
        cout << LCA(x,y) << endl;
    }
    
    for (int i = 0; i <= n; i++) {
        cout << lg[i] << " ";    
    }
    cout << endl;

    return 0;
}
