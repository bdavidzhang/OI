#include<bits/stdc++.h>
#include <iomanip>
using namespace std;
#define sz(x) (int)(x).size()
#define pb push_back
#define all(x) (x).begin(), (x).end()
using db = double;
const db eps = 1e-9, PI = acos(-1.0);
int sgn(db x){ return fabs(x) < eps ? 0 : (x < 0 ? -1 : 1);}
struct P {
    db x, y;
    P(db x = 0, db y = 0) : x(x), y(y) {}
    P operator-(P b) const { return P(x - b.x, y - b.y); }
};
db dot(P a, P b) { return a.x * b.x + a.y * b.y; }
db len(P a) { return sqrt(dot(a, a)); }
 
vector<db> circleCover(vector<P> o, vector<db> r) {
    int n = sz(o);
    vector<db> res(n + 1);
    for (int i = 0; i < n; ++i) {
        vector<pair<db, int>> ev;
        int cnt = 0;
        for (int j = 0; j < n; ++j) if(j != i) {
            db d = len(o[j] - o[i]);
            int c = sgn(d + r[i] - r[j]);
            if(c < 0 || (!c && (sgn(d) || j < i))) { ++cnt; continue; }
            if(sgn(d - r[i] - r[j]) >= 0 || sgn(d + r[j] - r[i]) <= 0) continue;
            db base = atan2(o[j].y - o[i].y, o[j].x - o[i].x);
            db t = acos(max((db)-1, min((db)1, (r[i] * r[i] + d * d - r[j] * r[j]) / (2 * r[i] * d))));
            db a = base - t, b = base + t;
            if(a < -PI) a += 2 * PI;
            if(b > PI) b -= 2 * PI;
            if(a > b) ++cnt;
            ev.pb({a, 1}), ev.pb({b, -1});
        }
        sort(all(ev));
        db cur = -PI;
        auto add = [&](db b) {
            res[cnt + 1] += (r[i] * r[i] * (b - cur) + o[i].x * r[i] * (sin(b) - sin(cur)) - o[i].y * r[i] * (cos(b) - cos(cur))) / 2;
            cur = b;
        };
        for (auto [a, v] : ev) add(a), cnt += v;
        add(PI);
    }
    return res;
}

const db INF = 1e18;


void solve(){
  int N, K;
  db R,C;
  cin >> R >> N >> K >> C;
  vector<P> o(N); vector<db> th(N);
  for(int i = 0; i < N; ++i){
    cin >> th[i];
    o[i] = P(R*cos(th[i]),R*sin(th[i]));
  }
  P O(0,0);
  db S = circleCover({O,o[0]}, {R,C})[2];
  
  vector<vector<db>> w(N,vector<db>(N,0));
  for(int i = 0;i < N; ++i)
    for(int j = i+1; j < N; ++j){
      db A = circleCover({O,o[i],o[j]}, {R,C,C})[3];
      if(th[j] - th[i] > PI) w[j][i] = A;
      else w[i][j] = A;
    }
  

  db best = INF;
  for(int f = 0; f <= N - K; ++f){
    vector<vector<db>> dp(K+1,vector(N,INF));
    dp[1][f] = 0;
    for(int c = 2; c <= K; ++c){
      for(int j = f+1; j < N; ++j){
        for(int i = f; i < j; ++i){
          if(dp[c-1][i] < INF) dp[c][j] = min(dp[c][j],dp[c-1][i] + w[i][j]);
        }
      }
    }
    for(int j = f; j < N; ++j)
      if(dp[K][j] < INF) best = min(dp[K][j]+w[j][f], best);
  }
  cout << setprecision(10) << fixed << K * S - best << endl;
  
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  solve();
  return 0;
}
