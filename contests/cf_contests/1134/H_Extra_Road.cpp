// H. Extra Road
// https://codeforces.com/contest/2290/problem/H  (2000 ms, 256 MB)
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


template <typename F>
ll binary_search(F check, ll ok, ll ng){
  while (ng - ok > 1){
    ll mid = (ok + ng ) /2;
    if(check(mid)) ok = mid; 
    else ng = mid;
  }
  return ok;
}

struct Tree {
    int n;
    vector<vi> g;
    vi parent, depth, sub, heavy, head, order;

    Tree(const vector<vi>& g) : n(sz(g)), g(g) {
        parent.assign(n, -1);
        depth.assign(n, 0);
        sub.assign(n, 1);
        heavy.assign(n, -1);
        head.assign(n, 0);

        order.push_back(0);

        for(int i = 0; i < sz(order); ++i){
          int v = order[i];

          for(int u : g[v]) {
            if(u == parent[v])continue;
            parent[u] = v;
            depth[u] = depth[v] + 1;
            order.push_back(u);
          }
        }


        for (int i = n - 1; i >= 0; --i) {
            int v = order[i];
            for (int u : g[v]) {
                if (u == parent[v]) continue;
                sub[v] += sub[u];
                if (heavy[v] == -1 || sub[u] > sub[heavy[v]])
                    heavy[v] = u;
            }
        }

        for (int v : order) {
            for (int u : g[v]) {
                if (u == parent[v]) continue;
                head[u] = (u == heavy[v] ? head[v] : u);
            }
        }
    }

    int subtree_size(int v) const {
        return sub[v];
    }

    int LCA(int a, int b) const {
        while (head[a] != head[b]) {
            if (depth[head[a]] > depth[head[b]])
                a = parent[head[a]];
            else
                b = parent[head[b]];
        }
        return depth[a] < depth[b] ? a : b;
    }

    int dist(int a, int b) const {
        int c = LCA(a, b);
        return depth[a] + depth[b] - 2 * depth[c];
    }
};

void solve() {
  int n;
  cin >> n;

  vector<vi> adj(n);
  for(int i = 0;i < n-1; ++i){
    int a,b;
    cin >> a >> b;
    --a; --b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  Tree tree(adj);

  auto check = [&](ll k) -> bool{
    if(k <= 1) return true;
    k = n - k;
    int a = 0, b = 0;
    bool notok = 0;

    auto add = [&](int v) -> void {
      int ab = tree.dist(a,b);
      int av = tree.dist(a,v);
      int bv = tree.dist(b,v);
      int ma = max({ab,av,bv});

      if(ma == ab){}
      else if(ma == av) swap(b,v);
      else if(ma == bv) swap(a,v);

      if(tree.dist(a,b) != tree.dist(a,v) + tree.dist(b,v)) notok = 1;
    };
    for(int v = 1; v < n; ++v){
      int x = tree.subtree_size(v);
      if(x <= k) continue; 
      add(v);
      add(tree.parent[v]);
    } 
    
    return !notok;
  };

  ll ans = binary_search(check, 1LL, (ll) n + 1);
  cout << ans << endl;

}


int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int T = 1;
  cin >> T;
  while (T--) solve();
  return 0;
}
