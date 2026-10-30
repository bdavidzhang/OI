#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<long long>;
using tiii = tuple<int,int,int>;
using vii = vector<int,int>;
using vb = vector<bool>;
#define all(v) ((v).begin()),((v).end())
#define sz(v) ((int)((v).size()))
#define fi first
#define se second
#define mp make_pair
#define pb push_back

const int INF = 1e9;
const ll LINF = 1e18;
const ll MOD = 1e9+7;
int dx[] = {1,0,-1,0}, dy[] = {0,1,0,-1};

//-------------geometry------------------
using db = double;
const db eps = 1e-9, PI = acos(-1.0);
int sgn(db x){return fabs(x) < eps ? 0 : (x < 0 ? -1 : 1);}
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

P proj(P p, P a, P b) { // projection of p onto line ab
    P d = b - a;
    return a + d * (dot(p - a, d) / dot(d, d));
}
P refl(P p, P a, P b) { return proj(p, a, b) * 2 - p; } // mirror of p over line ab
db disLine(P p, P a, P b) { return fabs(cross(a, b, p)) / len(b - a); }
db disSeg(P p, P a, P b) {
    if(sgn(dot(p - a, b - a)) < 0) return len(p - a);
    if(sgn(dot(p - b, a - b)) < 0) return len(p - b);
    return disLine(p, a, b);
}
bool onSeg(P p, P a, P b) { // endpoints count
    return !sgn(cross(p, a, b)) && sgn(dot(a - p, b - p)) <= 0;
}
bool segInter(P a, P b, P c, P d) { // touching and collinear overlap count
    int d1 = sgn(cross(a, b, c)), d2 = sgn(cross(a, b, d));
    int d3 = sgn(cross(c, d, a)), d4 = sgn(cross(c, d, b));
    if(d1 * d2 < 0 && d3 * d4 < 0) return true;
    return onSeg(c, a, b) || onSeg(d, a, b) || onSeg(a, c, d) || onSeg(b, c, d);
}
P lineInter(P a, P b, P c, P d) { // line ab meets line cd; make sure they're not parallel
    db s1 = cross(c, d, a), s2 = cross(c, d, b);
    return (a * s2 - b * s1) / (s2 - s1);
}
vector<P> segSeg(P a, P b, P c, P d) { // segment intersection points; collinear overlap gives both ends
    if(sgn(det(b - a, d - c))) {
        if(!segInter(a, b, c, d)) return {};
        return {lineInter(a, b, c, d)};
    }
    vector<P> r;
    if(onSeg(a, c, d)) r.pb(a);
    if(onSeg(b, c, d)) r.pb(b);
    if(onSeg(c, a, b)) r.pb(c);
    if(onSeg(d, a, b)) r.pb(d);
    sort(all(r));
    r.erase(unique(all(r)), r.end());
    return r;
}

int half(P a) { return sgn(a.y) < 0 || (!sgn(a.y) && sgn(a.x) < 0); } // [0, pi) -> 0, [pi, 2pi) -> 1
bool cmpAng(P a, P b) {
    int x = half(a), y = half(b);
    return x != y ? x < y : sgn(det(a, b)) > 0;
}
// sort(all(v), cmpAng); to sort around o, subtract o from every point first
db area(vector<P>& A) { // signed, CCW is positive
    db s = 0;
    int n = sz(A);
    for (int i = 0; i < n; ++i) s += det(A[i], A[(i + 1) % n]);
    return s / 2;
}
int inPoly(P p, vector<P>& A) { // any simple polygon: 2 on edge, 1 inside, 0 outside
    int n = sz(A), w = 0;
    for (int i = 0; i < n; ++i) {
        P a = A[i], b = A[(i + 1) % n];
        if(onSeg(p, a, b)) return 2;
        int k = sgn(cross(a, b, p)), d1 = sgn(a.y - p.y), d2 = sgn(b.y - p.y);
        if(k > 0 && d1 <= 0 && d2 > 0) ++w;
        if(k < 0 && d2 <= 0 && d1 > 0) --w;
    }
    return w != 0;
}
bool inConvex(P p, vector<P>& A) { // A CCW, no 3 collinear, n >= 3; edge counts as inside; O(log n)
    int n = sz(A);
    if(sgn(cross(A[0], A[1], p)) < 0 || sgn(cross(A[0], A[n - 1], p)) > 0) return false;
    int l = 1, r = n - 1;
    while(r - l > 1) {
        int m = (l + r) / 2;
        if(sgn(cross(A[0], A[m], p)) >= 0) l = m;
        else r = m;
    }
    return sgn(cross(A[l], A[r], p)) >= 0;
}
vector<P> convexCut(vector<P>& A, P a, P b) { // part of convex A left of line ab, still CCW
    vector<P> r;
    int n = sz(A);
    for (int i = 0; i < n; ++i) {
        P c = A[i], d = A[(i + 1) % n];
        int s1 = sgn(cross(a, b, c)), s2 = sgn(cross(a, b, d));
        if(s1 >= 0) r.pb(c);
        if(s1 * s2 < 0) r.pb(lineInter(a, b, c, d));
    }
    return r;
}

vector<P> hull(vector<P> A) {
    sort(all(A));
    A.erase(unique(all(A)), A.end());
    int n = sz(A), k = 0;
    if(n <= 2) return A;
    vector<P> H(2 * n);
    for (int i = 0; i < n; ++i) { // lower hull
        while(k >= 2 && sgn(cross(H[k - 2], H[k - 1], A[i])) <= 0) --k;
        H[k++] = A[i];
    }
    for (int i = n - 2, t = k + 1; i >= 0; --i) { // upper hull
        while(k >= t && sgn(cross(H[k - 2], H[k - 1], A[i])) <= 0) --k;
        H[k++] = A[i];
    }
    H.resize(k - 1);
    return H;
}

db diameter(vector<P> H) { // H from hull()
    int n = sz(H);
    if(n <= 1) return 0;
    db r = 0;
    for (int i = 0, j = 1; i < n; ++i) {
        P a = H[i], b = H[(i + 1) % n];
        while(cross(a, b, H[(j + 1) % n]) > cross(a, b, H[j])) j = (j + 1) % n;
        r = max({r, len(a - H[j]), len(b - H[j])});
    }
    return r;
}


pair<db, vector<P>> minRect(const vector<P>& H) { // H from hull(), CCW
    int n = sz(H);
    if(n == 0) return {0, {}};
    if(n == 1) return {0, vector<P>(4, H[0])};
    if(n == 2) return {0, {H[0], H[1], H[1], H[0]}};

    db ans = 1e100;
    vector<P> rect(4);

    int j = 0, k = 0, l = 0;

    // Initialize extreme points for the first edge
    P d0 = H[1] - H[0];
    for(int t = 1; t < n; ++t) {
        if(det(d0, H[t] - H[0]) > det(d0, H[j] - H[0]))
            j = t;
        if(dot(d0, H[t]) > dot(d0, H[k]))
            k = t;
        if(dot(d0, H[t]) < dot(d0, H[l]))
            l = t;
    }

    for(int i = 0; i < n; ++i) {
        P a = H[i], d = H[(i + 1) % n] - a;

        // Maximum perpendicular projection
        while(sgn(det(d, H[(j + 1) % n] - a)
                - det(d, H[j] - a)) > 0)
            j = (j + 1) % n;

        // Maximum parallel projection
        while(sgn(dot(d, H[(k + 1) % n])
                - dot(d, H[k])) > 0)
            k = (k + 1) % n;

        // Minimum parallel projection
        while(sgn(dot(d, H[(l + 1) % n])
                - dot(d, H[l])) < 0)
            l = (l + 1) % n;

        db h = det(d, H[j] - a);
        db lo = dot(d, H[l]), hi = dot(d, H[k]);
        db len2 = dot(d, d);
        db A = h * (hi - lo) / len2;

        if(A < ans) {
            ans = A;

            P u = d / len2;
            P v = rot90(d) / len2;
            db base = det(d, a);

            rect[0] = u * lo + v * base;
            rect[1] = u * hi + v * base;
            rect[2] = u * hi + v * (base + h);
            rect[3] = u * lo + v * (base + h);
        }
    }
    return {ans, rect};
}


//-------------geometry------------------
using vp = vector<P>;

void solve(){
  int n;
  cin >> n;
  vp A(n);
  for(int i = 0; i < n; ++i) cin >> A[i];
  vp H = hull(A);
  auto [ans, B] = minRect(H);
  cout << ans << endl;
  sort(all(B),cmpAng);
  for(auto &p : B){
    cout << p.x << " " << p.y << endl;
  }
}



int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(5) << fixed;
  int T = 1;
  // cin >> T;
  while(T--){
    solve();
  }

  return 0;
}