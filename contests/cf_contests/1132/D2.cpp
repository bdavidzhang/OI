#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
#define fi first
#define se second
#define endl '\n'

using Edge = pair<int,int>;

vector<Edge> encode(int n, string &s){
  vector<Edge> edges;
  int p = -1;
  for(int i = 0; i < n-1; ++i){
    if(s[i] == '1'){
      p = i + 2;
      break;
    }
  }

  if(p == -1){
    edges.push_back({1,2});
    edges.push_back({2,3});
    edges.push_back({3,1});

    for(int v = 4; v <= n; ++v) edges.emplace_back(1,v);
  }else{
    for(int i = 0; i < n-1; ++i){
      int v = i + 2;
      if(s[i] == '1') edges.push_back({1,v});
      else edges.push_back({p,v});
    }
  }
  return edges; 
}

string decode(int n, vector<Edge> &edges){
  vector<vi> adj(n+1);
  for(auto [u,v] : edges){
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  vi color(n+1,-1);
  queue<int> q;
  color[1] = 0;
  q.push(1);

  while(!q.empty()){
    int u = q.front();
    q.pop();

    for(int v : adj[u]) {
      if(color[v] == -1){
        color[v] = color[u] ^ 1;
        q.push(v);
      }else if(color[v] == color[u]){
        return string(n-1,'0');
      }
    }
  }
  string s;
  for(int v =2 ; v <= n; ++v) s += char('0' + color[v]);
  return s;
}

void solve1(){
  int n; string s;
  cin >> n >> s;
  vector<Edge> g = encode(n,s);
  cout << sz(g) << endl;
  for(auto e : g){
    cout << e.fi << " " << e.se << endl;
  }
}

void solve2(){
  int n,m;
  cin >> n >> m;
  vector<Edge> g(m);
  for(int i = 0; i < m; ++i){
    int u,v;
    cin >> u >> v;
    g[i] = {u,v};
  }

  string ans = decode(n,g);
  cout << ans << endl;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  
  string s;
  cin >> s;
  if(s == "first"){
    int T;
    cin >> T;
    while(T--) solve1();
  }else{
    int T;
    cin >> T;
    while(T--) solve2();
  }

  return 0;
}