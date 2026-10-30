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
int n,m;
vector<bool> vis(MAXN);
vector<vector<int>> g(MAXN);
queue<pair<int,int>> q;
stack<int> s;
vector<int> d(MAXN);
vector<int> last(MAXN);

void bfs(int node){
    if(vis[node]) return;
    vis[node] = true;

    d[node] = 1;
    q.push(mp(node,1));
    last[node] = -1;
    while(!q.empty()){
        auto cur = q.front();
        q.pop();
        for(auto x : g[cur.fi]){
            if(!vis[x]){
                q.push(mp(x,cur.se+1));
                vis[x] = true;
                last[x] = cur.fi;
            }
        }
        d[cur.fi] = cur.se;
    }
}
   
void solve(){
    cin >> n >> m;    
    for (int i = 0; i < m; i++) {
        int a,b;
        cin >> a >>b;
        g[a].pb(b);
        g[b].pb(a);
    }

    for (int i = 0; i <= n; i++) {
       d[i] = -1; 
    }

    bfs(1);
    if(d[n] == -1) cout << "IMPOSSIBLE" << endl;
    else{
        cout << d[n] << endl;
        int cur = n;
        vector<int> ans;
        while(cur != -1){
            ans.pb(cur);
            cur = last[cur];
        }
        reverse(all(ans));
        for(auto it = ans.begin(); it != ans.end(); ++it){
            cout << *it << " ";
        }
        cout << endl;
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
