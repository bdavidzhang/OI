#include<bits/stdc++.h>
using namespace std;



int main(){
    int n, m;
  cin >> n >> m;
  vector<vector<int>> g(n);//adj list
  for(int i = 0;i < m; ++i) {
    int x,y;
    cin>>x>>y;
    --x,--y;
    g[x].emplace_back(y);
    g[y].emplace_back(x);
  }

  long long cyclen = 1e9, cyccnt = 0;

  auto bfs = [&](int s) {
    vector<int> dist(n,1e9);
    dist[s] = 0;
    queue<int> q{{s}};
    while(q.size()) {
      int x = q.front();
      q.pop();
      for(int y : g[x]) if(dist[y] == 1e9) {
        dist[y] = dist[x]+1;
        q.emplace(y);
      }
    }

    for(int x = 0; x < n; ++x) {
      int above = 0;
      for(int y : g[x]) if(dist[y] < dist[x]) ++above;
      if(above <= 1) continue;
      int len = 2*dist[x];
      if(len < cyclen) cyclen = len, cyccnt = 0;
      if(len == cyclen) cyccnt += above*(above-1)/2;
    }

    for(int x = 0; x < n; ++x){
      for(int y : g[x]) if(y < x && dist[x] == dist[y]) {
        int len = dist[x]+dist[y]+1;
        if(len < cyclen) cyclen = len, cyccnt = 0;
        if(len == cyclen) ++cyccnt;
      }
    }
  };

  for(int x = 0; x< n; ++x) bfs(x);

  cout << cyccnt/cyclen << endl;

  return 0;
}
