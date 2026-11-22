#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using pii = pair<int,int>;
#define pb push_back

constexpr int N = 50 * 50 + 10;
constexpr int INF = INT_MAX / 2;


int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  
  int n,k;
  cin >> n >> k;
  
  vector<vi> a(n, vi(n,0));
  int cnt = 0;
  vector<vi> ord(k+2);
  vector<pii> cor(N);
  vi dis(N,INF);


  for(int i = 0; i < n; ++i){
    for(int j = 0; j < n; ++j){
      cin >> a[i][j];
      ord[a[i][j]].pb(cnt);
      cor[cnt] = {i,j};
      cnt++;
    }
  }

  priority_queue<pii, vector<pii>, greater<pii>> pq;

  for(auto &c : ord[1]){
    dis[c] = 0;
    pq.emplace(0,c);
  }

  while(!pq.empty()){
    auto [d, cur] = pq.top();
    pq.pop();

    if(d != dis[cur]) continue; //overdue

    auto [i,j] = cor[cur];
    int l = a[i][j];
    for(auto &c : ord[l+1]){
      auto [x,y] = cor[c];
      int nd = d + abs(i-x) + abs(j - y);
      if(nd < dis[c]){
        dis[c] = nd;
        pq.emplace(nd,c);
      }
    }
  }

  int ans = INF;
  for(auto &c : ord[k]) ans = min(ans, dis[c]);
  cout << (ans == INF ? -1 : ans) << endl;

  return 0;
}
