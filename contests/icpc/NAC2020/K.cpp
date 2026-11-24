#include<bits/stdc++.h>
#include <iterator>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<long long>;


int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, q;
  cin >> n >> q;

  vector adj(n+1,vector<int>());

  for(int i = 0; i < n-1; ++i){
    int u,v; cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  int LOG = 1; 
  while((1 << LOG) <= n) LOG++;
  vi depth(n+1,-1);
  vector up(LOG, vi(n+1));

  queue<int> bfs; 
  bfs.push(1);
  depth[1] = 0;

  //bfs init
  while(!bfs.empty()){
    int u = bfs.front(); bfs.pop();

    for(int v : adj[u]){
      if(depth[v] != -1) continue;
      up[0][v] = u;
      depth[v] = depth[u] + 1;
      bfs.push(v);
    }
  }

  //build up
  for(int k = 1; k < LOG; ++k)
  for(int u = 1; u <= n; ++u){
      up[k][u] = up[k-1][up[k-1][u]];
    }

  //lca function
  auto lca = [&](int u, int v){
    if(depth[u] < depth[v]) swap(u,v);

    int d = depth[u] - depth[v];
    for(int k = 0; k < LOG; ++k){
      if((d >> k) & 1) u = up[k][u];
    }

    if(u == v) return u;

    for(int k = LOG - 1; k >= 0; --k){
      if(up[k][u] == up[k][v]) continue;
      u = up[k][u], v = up[k][v];
    }

    return up[0][u];
  };

  while(q--){
    int r, p;
    cin >> r >> p;
    int d = depth[r] + depth[p] - 2*depth[lca(r,p)];
    ll ans;
    ans = n + 1LL * d*(d+1) / 2; 
    cout << ans << endl;
  }

  return 0;
}


