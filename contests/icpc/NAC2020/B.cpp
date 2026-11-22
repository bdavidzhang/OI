#include <algorithm>
#include<bits/stdc++.h>
#include <cstdint>
using namespace std;

using ll = long long;
using vi = vector<int>; 
using pii = pair<int,int>;

#define all(x) (x).begin(), (x).end()
#define endl '\n'

using Mask = uint32_t;

void solve(){
  int n,k;
  cin >> n >> k;

  auto bit = [n](int r, int c) -> Mask{
    return Mask{1} << (r * n + c);
  };

  Mask h = 0, m = 0;//hit / miss 
  for(int r = 0; r < n; ++r){
    string row; cin >> row;
    for(int c = 0; c < n; ++c){
      if(row[c] == 'O') h |= bit(r,c); //update hits
      if(row[c] == 'X') m |= bit(r,c); //update misses
    }
  }

  vi len(k);
  for(int &l : len) cin >> l;
  sort(all(len)); reverse(all(len));

  vector<vector<Mask>> put(k);
  for(int i = 0; i < k; ++i){
    int l = len[i];
    for(int r = 0; r < n; ++r){
      for(int c = 0; c < n; ++c){
        if(c + l <= n){
          Mask p = 0;
          for(int d = 0; d < l; ++d) p |= bit(r,c + d);

          if((p & m) == 0) put[i].push_back(p);
        }

        if(l > 1 && r + l <= n){
          Mask p = 0; 
          for(int d = 0 ; d < l; ++d) p |= bit(r + d, c);
          if((p & m) == 0) put[i].push_back(p);
        }
      }
    }
  }


  auto dfs = [&](auto self, int i, Mask used) -> ll{
    if(i == k) return (used & h) == h;
    ll ans = 0;

    for (Mask p : put[i]) 
      if((used & p) == 0) ans += self(self, i + 1, used | p);

    return ans;

    };

  cout << dfs(dfs,0,0) << endl;
}



int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  solve();
  


  return 0;
}

