#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<long long>;
using tiii = tuple<int,int,int>;
using vii = vector<vector<int>>;
using ld = long double;
using pii = pair<int,int>;
using vb = vector<bool>;
#define all(v) ((v).begin()), ((v).end())
#define sz(v) ((int)((v).size()))
#define fi first
#define se second 
#define mp make_pair
#define pb push_back

const int INF = 1e9;
const ll LINF = 1e18;
const ll MOD = 1e9+7; // or 998244353
int dx[] = {1,0,-1,0}, dy[] = {0,1,0,-1}; //movement 4 dir 


//----------------geometry--------------------
using db = long double;
const db eps = 1e-9, PI = acos(-1.0);
int sgn(db x){ return fabs(x) < eps 
  ? 0 : (x < 0 ? -1 : 1);} //sign 
struct P {
  db x,y ;
  P(db x = 0, db y = 0) : x(x), y(y) {}
  P operator+(P b) const { return P(x + b.x, y + b.y);}
  P operator-(P b) const { return P(x - b.x, y - b.y);}
  P operator*(db k) const { return P(x*k,y*k);}
  P operator/(db k) const { return P(x/k,y/k);}
  bool operator<(P b) const {return sgn(x - b.x) ? 
    x < b.x : sgn(y - b.y) < 0;} // is the x coord of target point greater than current point? if not, is the y?
  bool operator==(P b) const {return !sgn(x - b.x) && !sgn(y-b.y);}
};
istream& operator>>(istream& in, P &p){
  return in >> p.x >> p.y;
}
db dot(P a, P b){ return a.x * b.x + a.y*b.y;}
db det(P a, P b){ return a.x * b.y - b.x * a.y;}
db cross(P o, P a, P b){
  return det((a-o),(b-o));
}
db len(P a) { return sqrt(dot(a,a));}
P rot(P a, db t){ return P(a.x * cos(t) - a.y * sin(t), a.x* sin(t) + a.y*cos(t));}
P rot90(P a){ return P(-a.y, a.x);}


P proj(P p, P a, P b){ //proj of p onto line ab
   P d = b -a; 
  return a + d * (dot(p - a, d) / dot(d,d));
}
//mirror of p over line ab
P refl(P p, P a, P b){ return proj(p,a,b) * 2 - p;}
db disLine(P p, P a, P b){ //distance to line ab
  return fabs(cross(a,b,p)) / len(b-a);
}
db disSeg(P p, P a, P b){ //distnace to segment ab
  if(sgn(dot(p-a,b-a)) < 0) return len(p-a);
  if(sgn(dot(p-b,a-b)) < 0) return len(p-b);
  return disLine(p,a,b);
}
bool onSeg(P p, P a, P b){//endpoints count
  return !sgn(cross(p,a,b)) && sgn(dot(a-p,b-p)) <= 0;
}
bool segInter(P a, P b, P c, P d){
  //touching and collinear overlap count
  int d1 = sgn(cross(a,b,c)), d2 = sgn(cross(a,b,d));
  int d3 = sgn(cross(c,d,a)), d4 = sgn(cross(c,d,b));
  if(d1 * d2 < 0 && d3 * d4 < 0) return true;
  return onSeg(c,a,b) || onSeg(d,a,b) 
  || onSeg(a,c,d) || onSeg(b,c,d);
}
P lineInter(P a,P b, P c, P d){
  //line ab meets line cd; make sure they're not parallel
  db s1 = cross(c,d,a), s2 = cross(c,d,b);
  return (a * s2 - b * s1) / (s2 - s1);
}
vector<P> segSeg(P a, P b, P c, P d){
  //segment intersectoin points; collinear overlap gives 
  //both ends
  if(sgn(det(b-a, d-c))){
    if(!segInter(a,b,c,d)) return {};
    return {lineInter(a,b,c,d)};
  }
  vector<P> r;
  if(onSeg(a,c,d)) r.pb(a);
  if(onSeg(b,c,d)) r.pb(b);
  if(onSeg(c,a,b)) r.pb(c);
  if(onSeg(d,a,b)) r.pb(d);
  sort(all(r));
  r.erase(unique(all(r)),r.end());
  return r;
}
int half(P a){
  return sgn(a.y) < 0 || (!sgn(a.y) && sgn(a.x) < 0);
}//[0,pi] -> 0, [pi,2pi) -> 1
bool cmpAng(P a, P b){
  int x = half(a), y = half(b);
  return x != y ? x < y : sgn(det(a,b)) > 0;
} //sort(all(v), cmpAng) to sort around o
//subtract from o every point first

//note: if x is close to 0.0, it may be negative, 
//so do if(fabs(P.x) < 0.005) P.x = 0.0, same for y

db area(vector<P> &A){//signed, counter clockwise is positive
  db s = 0;
  int n = sz(A);
  for (int i = 0; i < n; ++i) s += det(A[i], A[(i+1)%n]);
  return s / 2;
}
int inPoly(P p, vector<P> & A){
  //any simple polygon, O(n)
  //2 on edge, 1 inside, 0 outside
  int n = sz(A), w = 0;
  for(int i = 0; i < n; ++i){
    P a = A[i], b = A[(i+1) % n];
    if(onSeg(p,a,b)) return 2;
    int k = sgn(cross(a,b,p)), d1 = sgn(a.y - p.y), d2 = sgn(b.y - p.y);
    if(k > 0 && d1 <= 0 && d2 > 0) ++w;
    if(k < 0 && d2 <= 0 && d1 > 0) --w;
  }
  return w != 0;
}
int inConvex(P p, vector<P> &A){
  //is point p in polygon A
  //A CCW, no 3 collinear, n >= 3, edge counts as inside 
  //O(log n)
  //2 on edge, 1 inside, 0 outside
  int n = sz(A);
  int c1 = sgn(cross(A[0],A[1],p)),
  c2 = sgn(cross(A[0],A[n-1],p));
  if(c1 < 0 || c2 > 0) return 2;
  else if(c1 == 0) return onSeg(p,A[0],A[1]) ? 2 : 0;
  else if(c2 == 0) return onSeg(p,A[0],A[n-1]) ? 2 : 0;
  if(sgn(cross(A[0], A[1], p)) < 0 || 
  sgn(cross(A[0], A[n-1] ,p)) > 0) return false; //is p inside these rays
  int l = 1, r = n-1;
  while(r - l > 1 ) { //binary search to find which fan p is in
    int m = (l+r) / 2;
    if(sgn(cross(A[0], A[m], p)) >= 0) l = m;
    else r = m;
  }
  if(sgn(cross(A[l], A[r], p)) > 0) return 1;
  if(sgn(cross(A[l], A[r], p)) == 0) return 2;
  return 0;
}
vector<P> convexCut(vector<P> &A, P a, P b){
  //part of convex A left of line ab, still CCW
  vector<P> r ;
  int n = sz(A);
  for(int i = 0; i < n; ++i){
    P c = A[i], d = A[(i+1) % n];
    int s1 = sgn(cross(a,b,c)), s2 = sgn(cross(a,b,d));
    if(s1 >= 0) r.pb(c);
    if(s1 * s2 < 0) r.pb(lineInter(a,b,c,d));
  }
  return r;
}

//----------------geometry--------------------



void solve(){
  int n,m;
  cin >> n;
  vector<P> A(n); //A is in CW
  for(int i = 0; i < n; ++i) cin >> A[i];
  reverse(all(A)); //A is in CCW
  cin >> m;
  bool ok = true;
  for(int i = 0; i < m; ++i){
    P x;
    cin >> x;
    int ans = inConvex(x,A);
    if(ans != 1){
      ok = false;
    }
  }
  
  cout << (ok ? "YES" : "NO") << '\n';
}


int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(2) << fixed; 
  int T = 1;
  // cin >> T;
  while(T--){
    solve();
  }
  return 0;
}