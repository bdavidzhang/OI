#include<bits/stdc++.h>
using namespace std;

int n,m,k,d,s,t, dis[109][109][109], hd[109], tot;
bool S[109][109][109];
int W[109][109]; 
bool vs[109][109][109];
struct edge{int t,w,nxt;} es[20009];
void adde(int u, int v,int w) {
  es[++tot] = (edge){v,w,hd[u]}, hd[u] = tot;
  es[++tot] = (edge){u,w,hd[v]}, hd[v] = tot;
}



struct dat{
  int a,b,c;
  bool operator < (const dat & A) const {return a < A.a || a == A.a && b < A.b || a == A.a && b == A.b && c < A.c;}
};
priority_queue<pair<int, dat>> q; 
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n>>m>>k>>d>>s>>t;
  for(int i=1;i<=m;++i) {
    int u,v,w; cin>>u>>v>>w;
    W[u][v] = W[v][u] = w; 
    adde(u,v,w);
  }
  for(int i=1;i<=k;++i) {
    int a,b,c; cin >> a>> b>>c;
    S[a][b][c] = 1;
  }
  for(int i=1;i<=n;++i) 
    for(int j=1;j<=n;++j)
      for(int w=0;w<=d;++w) 
        dis[i][j][w] = 1e9;

  dis[s][s][0] = 0; 
  q.emplace(0, (dat){s,s,0});
  while(q.size()) {
    dat now = q.top().second; q.pop();
    if(vs[now.a][now.b][now.c]) continue;
    int u = now.a, x = now .b, cur = now.c; 
    vs[u][x][cur] =1;
    for(int i = hd[u]; i;i=es[i].nxt) {
      int v= es[i].t ;
      if(v == x) continue; 
      if(S[x][u][v]) {
        int now = cur + (cur == 0 ?W[x][u] + W[u][v]: W[u][v]); 
        if(now <= d && dis[v][u][now] > dis[u][x][cur] + W[u][v]) {
          dis[v][u][now]  = dis[u][x][cur] + W[u][v]; 
          q.emplace(-dis[v][u][now], (dat){v,u,now});
        }
      } else {
        if(dis[v][u][0] > dis[u][x][cur] + W[u][v]) {
          dis[v][u][0] = dis[u][x][cur] + W[u][v]; 
          q.emplace(-dis[v][u][0], (dat){v,u,0});
          
        }
      }
    }
  }
   int ans = 1e9; 
  for(int u=1;u<=n;++u)
    for(int v = 0; v<=d;++v)
      ans = min(ans, dis[t][u][v]);
  if(ans == 1e9) cout << "impossible"; 
  else cout << ans << endl;
  return 0; 
}