// G. Path Queries
// https://codeforces.com/problemset/problem/1213/G?utm_source=chatgpt.com  (3000 ms, 256 MB)
#include <bits/stdc++.h>
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
#define endl '\n'
#define int long long 

struct DSU{
  int n;
  vi sz, par;

  DSU(int n) : n(n), sz(n,1), par(n){
    iota(all(par), 0);
  }

  int find(int x){
    if(x == par[x]) return x;
    return par[x] = find(par[x]);
  }

  bool unite(int x, int y){
    int rx = find(x), ry = find(y);
    if(rx == ry) return false;
    if(sz[rx] < sz[ry]) swap(rx,ry);

    sz[rx] += sz[ry];
    par[ry] = rx;
    return true;
  }


  bool same(int x, int y){ return find(x) == find(y);}

  int size(int x){return sz[find(x)];}  

};

struct Edge{
  int u,v,w;
};

struct Query{
  int idx,x;
};


void solve(){
  int n,q;
  cin >> n >> q;
  vector<Query> qs(q);
  vi ans(q);
  vector<Edge> es(n-1);
  for(int i = 0; i < n-1; ++i){
    int u,v,w;
    cin >> u >> v >> w;
    es[i] = {u,v,w};
  }
  for(int i = 0; i < q; ++i){
    int x; cin >> x;
    qs[i] = {i,x};

  }

  auto cmp1 = [&](Edge &e1, Edge &e2){
    return e1.w < e2.w;
  };

  auto cmp2 = [&](Query &q1, Query &q2){
    return q1.x < q2.x;
  };


  sort(all(es),cmp1);
  sort(all(qs),cmp2);

  DSU d(n+10);
  int cur = 0;
  int j = 0;

//  for(auto e : es ) cout << e.w << " ";
//  cout << endl;
//
//  for(auto q : qs) cout << q.x << " ";
//  cout << endl;

  for(int i = 0; i < q; ++i){
    int w = qs[i].x;
    while(j < n-1 && es[j].w <= w){
      int u = es[j].u, v = es[j].v;
      //cout << d.size(u) << endl; 
      //cout << d.size(v) << endl;
      if(!d.same(u,v))cur += 1LL * d.size(u) * d.size(v);
      //for(auto x : d.par) cout << x <<" ";
      //cout << endl;
      d.unite(u,v);
      //cout << out << endl;
      //for(auto x : d.par) cout << x <<" ";
      //cout << endl;
      j++;
    }
    ans[qs[i].idx] = cur;
    //cout << cur << endl;
  }

  for(int i = 0; i < q; ++i) cout << ans[i] << " ";
  cout << endl;
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int T = 1;
  while (T--) solve();
  return 0;
}
