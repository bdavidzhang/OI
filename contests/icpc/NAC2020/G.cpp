#include <algorithm>
#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>; 
using pii = pair<int,int>;

#define all(x) (x).begin(), (x).end()
#define endl '\n'


template<typename F> 
int binary_search(F check, int ok, int ng){
  while(abs(ok - ng) > 1){
    int mid = (ok + ng) / 2;
    if (check(mid)) ok = mid; 
    else ng = mid;
  }
  return ok;
}


void solve(){
  int n, p, q, s;
  cin >> n >> p >> q >> s;

  vi a(p), b(q);
  for(auto &x : a) cin >> x;
  for(auto &x : b) cin >> x;

  auto check = [&](int d) -> bool{
    vector<pii> seg;

    for(auto x : a){
      int l = x - d;
      int r = min(x + d, s - x);

      if(l <= r) seg.emplace_back(r,l);
    }

    sort(all(seg));

    multiset<int> st(all(b));

    int cnt = 0;

    for (auto [r,l] : seg){
      auto it = st.lower_bound(l);

      if(it == st.end() || *it > r) continue;

      st.erase(it);

      if(++cnt == n) return true;
    }
    return false;

  };

  if(!check(1e9)) cout << -1 << endl;

  else cout << binary_search(check, 1e9, -1) << endl;
}



int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  solve();
  


  return 0;
}
