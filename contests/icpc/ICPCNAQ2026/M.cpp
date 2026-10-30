#include<bits/stdc++.h>
using namespace std;

long long getpair(vector<long long> a, long long k){
  sort(a.begin(),a.end());
  long long res = 0;
  for (long long x : a){
    auto [lo, hi] = std::equal_range(a.begin(),a.end(),x - k);
    res += hi - lo;
  }
  return res;
}



void solve(){
  long long n,k;
  cin >> n >> k;
  vector<long long> v(n);
  for(int i = 0; i < n; ++i){
    cin >> v[i];
  }

  vector<vector<int>> adj(n);
  for(int i = 0;i < n; ++i){
    int a, b; cin >> a >> b;
    a--; b--;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  vector<int> deg(n);
  vector<bool> seen(n, false);
  queue<int> q;



  for (int i = 0; i < n; ++i){
    deg[i] = adj[i].size();
    if (deg[i] == 1) q.push(i);
  }
  while(!q.empty()){
    int u = q.front();
    q.pop();
    seen[u] = true;
    for (int w : adj[u]){
      if((seen[w] == false) && (--deg[w] == 1))  q.push(w);
    }
  }
  //the roots of cycle will not be seen

  vector<int> root(n,-1);
  for(int i = 0; i < n; ++i){
    if (seen[i]) continue;
    root[i] = i;
    vector<int> st = {i};
    //dfs to build tree
    while(!st.empty()){
      int cur = st.back(); 
      st.pop_back();
      for (int w : adj[cur]){
        if (root[w] == -1 && seen[w]){
          root[w] = i;
          st.push_back(w);
        }
      }
    }
  }
  
  vector<vector<long long>> gt(n);
  for(int i = 0; i < n; ++i){
    gt[root[i]].push_back(v[i]);
  }
  long long T = getpair(v,k);
  long long S = 0;
  for (auto& grouptree : gt){
    if (!grouptree.empty()) S += getpair(grouptree,k);
  }
  
  long long ans = 2 * T - S;
  cout << ans << '\n';

  //first, the graph G must be a cycle +
  //trees because it has n edges 
  //with n - 1 edges forming a tree, the 
  //last edge must form a cycle 
  //so the graph is shaped like a keychain
  //for two nodes to count, the value diff  = k
  //if they are in diff trees,
  // there are 2 ways to go, 
  //left or right 
  //if they rae in the same tree 
  //there is 1 way to go 
  //so we count the total num of pairs 
  //and the subtract by those in the same tree 

  //first find the loop by peeling 
  //this is the same idea as toposrot actually
  //but instead of indegree, its just degree 
  
  //then build the tree via dfs 
  //finally find the way to count these pairs 
  //by sorting and then just iterating. 

}


int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  solve();
  return 0;
}