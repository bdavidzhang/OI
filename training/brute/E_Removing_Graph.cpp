// E. Removing Graph
// https://codeforces.com/contest/1823/problem/E  (2000 ms, 256 MB)
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
#define sz(x) (int)(x).size()
#define endl '\n'

struct DSU {
  vi f, siz;
  DSU() {} 
  DSU(int n){init(n);}

  void init(int n ){
    f.resize(n) ;
    iota(all(f),0);
    siz.assign(n,1);
  }

  int find(int x){
    while(x != f[x]){
      x = f[x] = f[f[x]];
    }
    return f[x];
  }


  bool merge(int x, int y){
    x = find(x);
    y = find(y);
    if(x == y) return false;
    if(siz[x] < siz[y]) swap(x,y);  
    f[y] = x;
    siz[x] += siz[y];
    return false;
  }



  bool same(int x, int y){
    return find(x) == find(y);
  }

  int size(int x){
    return siz[x];
  }
};



void solve() {
  int n,l,r;
  cin >> n >> l >> r;
  DSU dsu(n);
  for(int i = 0;i < n; ++i){
    int u,v;
    cin >> u >> v;
    u--;v--;
    dsu.merge(u,v);
  }

  int ans = 0;
  for(int i = 0 ;i < n; ++i){
    if(dsu.find(i) == i){
      int s = dsu.size(i);
      ans ^= (s >= l + r) ? 0 : s / l;
    }
  }
  if(ans) cout << "Alice" << endl;
  else cout << "Bob" << endl;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int T = 1;
  while (T--) solve();
  return 0;
}
