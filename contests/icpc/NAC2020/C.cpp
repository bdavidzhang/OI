#include<bits/stdc++.h>
#include <iterator>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<long long>;
using pii = pair<int,int>;
#define sz(x) ((int)(x).size())

struct Circle {
  ll x,y,r;
};

struct Arc {
  int id;
  int side;
};

struct Event {
  ll x;
  int id; 
  bool entering;

  bool operator<(const Event &other){
    return tie(x, entering, id) < tie(other.x, other.entering, other.id);
  }
};

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n,q;
  cin >> n >> q;

  int m = n + q;

  vector<Circle> circles(m);
  vector<Event> events; 
  events.reserve(2*m);;

  for(int i = 0; i < m; ++i){
    auto &[x,y,r] = circles[i];
    cin >> x >> y >> r;
    events.push_back({x - r, i, true});
    events.push_back({x+r, i, false});
  }

  sort(events.begin(),events.end());

  ll sweep_x = 0;
  auto height = [&](Arc arc){
    const auto &[x,y,r] = circles[arc.id];
    ll dx = sweep_x - x;
    return y + arc.side * sqrtl(r * r - dx * dx);
  };

  auto cmp = [&](Arc a, Arc b){
    long double ya = height(a), yb = height(b);
    if(ya != yb) return ya < yb;

    return tie(a.id, a.side) < tie(b.id, b.side);
  };

  set<Arc, decltype(cmp)> active(cmp);
  using Iterator = decltype(active)::iterator;
  vector<Iterator> lower(m), upper(m);

  int root = m;
  vi parent(m, root), order;
  order.reserve(m);

  for (auto [x,u, entering] : events){
    sweep_x = x;

    if(!entering){
      active.erase(lower[u]);
      active.erase((upper[u]));
      continue;
    }

    auto it = active.lower_bound({u,-1});
    if (it != active.end()){
      int v = it -> id;
      parent[u] = (it->side == 1 ? v : parent[v]);
    }

    lower[u] = active.insert({u,-1}).first;
    upper[u] = active.insert({u,1}).first;

    order.push_back(u);
  }

  vector<array<int,2>> sum(m + 1, {0,0});
  vi ans(q);

  reverse(order.begin(), order.end());
  for(int u : order){
    auto [a,b] = sum[u];
    int best = max(a, 1 + b);
    int p = parent[u];

    if(u < n){
      sum[p][0] += best;
      sum[p][1] += a;
    }else{
      ans[u - n] = best;
      sum[p][0] += a;
      sum[p][1] += b;
    }
  }

  for(int a : ans){
    cout << a << endl;
  }
  

  return 0;
}



