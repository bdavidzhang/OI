// Endless Holidays
// https://atcoder.jp/contests/abc456/tasks/abc456_e  (3000 ms, 1024 MB)
#include <bits/stdc++.h>
#include <vector>
using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vll = vector<ll>;
using vpii = vector<pii>;
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()
#define endl '\n'

void solve() {
  int n,m;
  cin >> n >> m;

  vector<vi> adj(n);
  for(int i = 0; i < m; ++i){
    int u,v;
    cin >> u >> v;
    u--;v--;
    adj[u].push_back(v);
    adj[v].push_back(u);

  }

  int w;
  cin >> w;

  vector<string> s(n);
  for(int i = 0; i < n; ++i) cin >> s[i];

  auto id = [&](int u, int d){
    return u * w + d; //1D index
  };

  vector<vi> g(n*w);
  vi indeg(n*w,0);

  int good = 0;

  for(int u = 0; u < n; ++u){
    for(int d = 0; d < w; ++d){
      if(s[u][d] == 'x') continue; 
      ++good;

      int from = id(u,d);
      int nd = (d+1) % w;

      if(s[u][nd] == 'o'){
        int to = id(u,nd);
        g[from].push_back(to);
        ++indeg[to];
      }

      for(int &v : adj[u]){
        if(s[v][nd] == 'o'){
          int to = id(v,nd);
          g[from].push_back(to);
          ++indeg[to];
        }
      }
    }
  }
    
  queue<int> q; 
  for(int u = 0; u < n; ++u){
    for(int d = 0; d < w; ++d){
      int st = id(u, d);
      if(s[u][d] == 'o' && indeg[st] == 0) q.push(st) ;
    }
  }

  int rem = 0;

  while(!q.empty()){
    int u = q.front();
    q.pop();
    ++rem;

    for(int v : g[u]){
      --indeg[v];
      if(indeg[v] == 0){
        q.push(v);
      }
    }
  }

  cout << (rem < good ? "Yes\n" : "No\n");


}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int T = 1;
  cin >> T;
  while (T--) solve();
  return 0;
}
