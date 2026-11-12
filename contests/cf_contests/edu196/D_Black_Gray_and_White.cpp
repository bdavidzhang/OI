#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve(){
  int n;
  cin >> n;
  
  vector<vector<int>> adj(n+1);
  for(int i = 0; i < n-1; ++i){
    int u,v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  if(n % 2 == 0){
    cout << n + 1 << '\n';
    return;
  }

  auto check = [&](int k, int ex) -> bool{
    vector<int> comp(n+1, -1);
    comp[ex] = 0;

    int id = 0;
    vector<int> st;
    for(int bg : adj[ex]){
      ++id;
      comp[bg] = id;
      st.push_back(bg);

      while(!st.empty()){
        int u = st.back();
        st.pop_back();

        for(int v : adj[u]){
          if(comp[v] != -1) continue;
          comp[v] = id;
          st.push_back(v);
        }
      }
    }

    for(int i = 1; i <= n; ++i){
      int j = k-i;
      if(j < 1 || j > n || i >= j) continue;

      if(comp[i] != comp[j]) return true;
    }
    return false;
  };

  if(check(n,n)) cout << n << '\n';
  else if(check(n+1,(n+1)/2)) cout << n + 1 << '\n';
  else if(check(n+2,1)) cout << n + 2 << '\n';
  else cout << n << '\n';
}



int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);   

  int T;
  cin >>T;
  while(T--)solve();

  return 0;
}