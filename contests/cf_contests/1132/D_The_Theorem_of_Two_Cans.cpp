
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
#define fi first
#define se second


using Edge = pair<int, int>;

vector<Edge> encode(int n, string& s) {
    vector<Edge> edges;

    int p = -1;
    for (int i = 0; i < (int)s.size(); ++i) {
        if (s[i] == '1') {
            p = i + 2;
            break;
        }
    }

    if (p == -1) {
        edges.emplace_back(1, 2);
        edges.emplace_back(2, 3);
        edges.emplace_back(3, 1);

        for (int v = 4; v <= n; ++v)
            edges.emplace_back(1, v);
    } else {
        for (int i = 0; i < (int)s.size(); ++i) {
            int v = i + 2;

            if (s[i] == '1')
                edges.emplace_back(1, v);
            else
                edges.emplace_back(p, v);
        }
    }

    return edges;
}

string decode(int n, vector<Edge>& edges) {
    vector<vector<int>> adj(n + 1);
    for (auto [u, v] : edges) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> color(n + 1, -1);
    queue<int> q;
    color[1] = 0;
    q.push(1);

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v : adj[u]) {
            if (color[v] == -1) {
                color[v] = color[u] ^ 1;
                q.push(v);
            } else if (color[v] == color[u]) {
                return string(n - 1, '0');
            }
        }
    }

    string s;
    for (int v = 2; v <= n; ++v)
        s += char('0' + color[v]);

    return s;
}


void solve1(){
  int n;
  cin >> n;
  string s;
  cin >> s;
  vector<Edge> g = encode(n,s);
  cout << sz(g) << '\n'; 
  for(Edge e : g){
    cout << e.fi << " " << e.se << '\n';
  }
}

void solve2(){
  int n,m;
  cin >> n >> m;
  vector<Edge> g; 
  for(int i = 0; i < m; ++i){
    int x,y;
    cin >> x >> y;
    g.push_back({x,y});
  }
  string ans = decode(n,g);
  cout << ans << '\n';
}



signed main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  string s;  
  cin >> s;
  if (s == "first"){
    int T;
    cin >>T ;
    while(T--)solve1();
  }else{
    int T;
    cin >>T ;
    while(T--)solve2();
  }



  return 0;
}


