#include<bits/stdc++.h>
using namespace std;
 
 
 int n, deg[109];
long long f[109];
vector<int> to[109];
void dfs(int u,int fa) {
    for(auto v : to[u]) if(v != fa) {
        
        f[v] = f[u] 
        dfs(v,u);
        
    }
}
 int main () {
     cin >> n; 
     for(int i=1;i<n;++i) {
         int u,v; cin>>u>>v;
         to[u].push_back(v);
         to[v].push_back(u);
     }
     double ans = 0;
     for(int i=1;i<=n;++i) {
         f[i] = 1; 
         dfs(i,0);
         for(int j=1;j<=n;++j) 
            ans += 1./f[j];
     }
     cout << ans / n << endl; 
     return 0;
 }
