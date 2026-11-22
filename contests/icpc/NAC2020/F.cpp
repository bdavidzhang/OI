#include<bits/stdc++.h>
#include <climits>
#include <vector>
using namespace std;

using vi = vector<int>;
using pii = pair<int,int>;

constexpr int INF = INT_MAX / 2;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n,k;
  cin >> n >> k;

  vector<vi> a(n,vi(n)), ord(k+2);
  vi dis(n*n+10,INF);
  vector<pii> cor(n*n+10);
  int cnt = 0;
  for(int i = 0; i < n; ++i)
    for(int j = 0; j < n; ++j){
      cin >> a[i][j];
      ord[a[i][j]].push_back(cnt);
      cor[cnt] = {i,j};
      cnt++;
    }

  for(auto &c : ord[1]) dis[c] = 0;

  for(int l = 1; l <= k; ++l){
    for(auto &u : ord[l]){
      for(auto &v : ord[l+1]){
        auto [i,j] = cor[u];
        auto [x,y] = cor[v];
        dis[v] = min(dis[v], dis[u] + abs(i - x) + abs(j - y));
      }
    }
  }

  int ans = INF;
  for(auto &c : ord[k]) ans = min(ans, dis[c]);

  cout << (ans == INF ? -1 : ans) << endl;





  return 0;

}
