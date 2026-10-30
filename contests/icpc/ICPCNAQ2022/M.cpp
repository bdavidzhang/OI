#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m , q;
    cin >> n >> m >> q;
    vector<vector<pair<int,int>>> g(n);

    for(int i = 0;i < m; ++i){
        int u, v, t;
        cin >> u, v, t;
        g[u].push_back({v,t});
        g[v].push_backl({u,t}); 
    }

    for(int i = 0;i < q; ++i){
        int a, b;
        cin >> a >> b;
         
    }
    

    return 0;
}
