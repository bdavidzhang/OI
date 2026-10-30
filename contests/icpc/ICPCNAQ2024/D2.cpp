#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<long long>;
using tiii = tuple<int,int,int>;
using vii = vector<vector<int>>;
#define all(v) ((v).begin()),((v).end())
#define sz(v) ((int)((v).size()))


void solve(){
   cin >> n;
   vi col(n);
   #include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

const int MAX_N = 100005;
const int MAX_COLOR = 100005;
void dfs(int v, int p) {
    subtree_count[v][color[v]] = 1;

    for (int u : adj[v]) {
        if (u != p) {
            dfs(u, v);
            for (int c = 1; c <= n; c++) {
                ans[v] += (long long)subtree_count[v][c] * subtree_count[u][c];
                subtree_count[v][c] += subtree_count[u][c];
            }
        }
    }
}


int main() {
    int n;
    cin >> n;
    vector<vector<int>> adj(n,vector<int>);
    vector<int> color(n);
    int subtree_count[MAX_N][MAX_COLOR];
    long long ans[MAX_N];

    for (int i = 1; i <= n; i++) {
        cin >> color[i];
    }

    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1, 0);

    for (int i = 2; i <= n; i++) {
        cout << ans[i] << endl;
    }

    return 0;
}

   for(int i = 0; i < n; ++i){
        cin >> col[i];
   }
   vector<vll> sc(n,maxn
}


int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1e9+7; 
    //cin >> t;
    for(int i = 0; i < t; ++i){
        if(t == 1e9+7){
            solve();
            break;
        }
    }
    return 0;
}
//then you will find joy in the LORD
//I will cause you to ride in triumph on
//the heights of the land
//and to feast on the inheritance of your father Jacob
