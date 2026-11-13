// B. Fox Dividing Cheese
// https://codeforces.com/contest/371/problem/B  (1000 ms, 256 MB)
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
#define int long long

int bfs(int a, int b) {
  queue<pair<pii,int>> q;
  set<pii> vis;

  q.push({{a,b},0});
  vis.insert({a,b});

  while(!q.empty()){
    auto [state,dist] = q.front();
    q.pop();
    auto [u,v] = state;
    if(u == v) return dist;
    for(auto p : {2,3,5}){
      if(u % p == 0){
        pii nxt = {u/p,v};
        if(vis.insert(nxt).second){
          q.push({nxt,dist+1});
        }
      }
      if(v % p == 0){
        pii nxt = {u,v/p};
        if(vis.insert(nxt).second){
          q.push({nxt,dist+1});
        }
      }

    }
  }

  return -1;
}

void solve(){
  int n,m;
  cin >> n >> m;
  cout << bfs(n,m) << endl;
}


signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int T = 1;
  while (T--) solve();
  return 0;
}
