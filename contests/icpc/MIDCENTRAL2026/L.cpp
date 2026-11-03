#include<bits/stdc++.h>
using namespace std;
#define sz(x) (int) (x).size()
#define pb push_back
#define all(x) (x).begin(), (x).end()
using db = double;
const db eps = 1e-9, PI = acos(-1.0);
int sgn(db x){ return fabs(x) < eps ? 0 : (x < 0 ? -1 : 1);}
struct P {
    db x, y;
    P(db x = 0, db y = 0) : x(x), y(y) {}
    P operator+(P b) const { return P(x + b.x, y + b.y); }
    P operator-(P b) const { return P(x - b.x, y - b.y); }
    P operator*(db k) const { return P(x * k, y * k); }
    P operator/(db k) const { return P(x / k, y / k); }
    bool operator<(P b) const { return sgn(x - b.x) ? x < b.x : sgn(y - b.y) < 0; }
    bool operator==(P b) const { return !sgn(x - b.x) && !sgn(y - b.y); }
};
istream& operator>>(istream& in, P& p) { return in >> p.x >> p.y; }
db dot(P a, P b) { return a.x * b.x + a.y * b.y; }
db det(P a, P b) { return a.x * b.y - a.y * b.x; }
db cross(P o, P a, P b) { return det(a - o, b - o); }
db len(P a) { return sqrt(dot(a, a)); }
P rot(P a, db t) { return P(a.x * cos(t) - a.y * sin(t), a.x * sin(t) + a.y * cos(t)); } // CCW by t
P rot90(P a) { return P(-a.y, a.x); }

vector<db> circleCover(vector<P> o, vector<db> r) { // res[k] = area covered by >= k circles
    int n = sz(o);
    vector<db> res(n + 1);
    for (int i = 0; i < n; ++i) {
        vector<pair<db, int>> ev; // (angle, +1 enter / -1 leave)
        int cnt = 0; // how many other circles cover angle -PI of circle i
        for (int j = 0; j < n; ++j) if(j != i) {
            db d = len(o[j] - o[i]);
            int c = sgn(d + r[i] - r[j]);
            if(c < 0 || (!c && (sgn(d) || j < i))) { ++cnt; continue; } // i inside j (equal circles: lower index covers)
            if(sgn(d - r[i] - r[j]) >= 0 || sgn(d + r[j] - r[i]) <= 0) continue; // apart, or j inside i
            db base = atan2(o[j].y - o[i].y, o[j].x - o[i].x);
            db t = acos(max((db)-1, min((db)1, (r[i] * r[i] + d * d - r[j] * r[j]) / (2 * r[i] * d))));
            db a = base - t, b = base + t;
            if(a < -PI) a += 2 * PI;
            if(b > PI) b -= 2 * PI;
            if(a > b) ++cnt; // range wraps over -PI
            ev.pb({a, 1}), ev.pb({b, -1});
        }
        sort(all(ev));
        db cur = -PI;
        auto add = [&](db b) { // arc [cur, b] of circle i, cnt other circles over it: boundary of the ">= cnt+1" region
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
  db R,C; int N, K;
  cin >> R >> N >> K >> C;
  vector<db> th(N); vector<P> o(N);
  for(int i = 0; i < N; ++i){
    cin >> th[i];
    o[i] = P(R*cos(th[i]), R*sin(th[i]));
  }
  P O(0,0);
  db S = circleCover({0, o[0]}, {R,C})[2]; // area covered by 2 circles
  
  // w[i][j] = overlap to subtract when j is the next chosen outlet CCW after i
  vector<vector<db>> w(N,vector<db>(N,0));
  for(int i = 0 ;i < N; ++i) for(int j = i+1; j < N; ++j){
    db A = circleCover({O,o[i],o[j]},{R,C,C})[3]; //tri circle intersectoin
    if(th[j] -th[i] < PI) w[i][j] = A; 
    else w[j][i] = A;   
  }

  //dp represents 从 f 开始、按下标递增已经选了 c 个插座、最后一个是 j 时，重叠面积之和的最小值。

  
  db best = INF;
  for(int f = 0; f + K <= N; ++f){
    vector<vector<db>> dp(K+1, vector<db>(N, INF));
    dp[1][f] = 0;
    for(int c = 2; c <= K; ++c)
      for(int j = f + 1; j < N; ++j)
        for(int i = f; i < j; ++i)
          if(dp[c-1][i] < INF) dp[c][j] = min(dp[c][j], dp[c-1][i] + w[i][j]);
    for(int j = f; j < N; ++j)
      if(dp[K][j] < INF) best = min(best, dp[K][j] + w[j][f]);  
  }
  cout << setprecision(10) << fixed << K * S - best << '\n';
}
  

int main(){
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  int T = 1;
  //cin >> T;
  while(T--) solve();

  return 0;
}
