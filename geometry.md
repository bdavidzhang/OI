# 计算几何

Every section builds on **基础**. Copy top to bottom; a section only uses the ones above it.
Assumes the usual header (`bits/stdc++.h`, `sz`, `all`, `pb`, `mp`, `fi`, `se`).

Conventions:
- points are passed by value (16 bytes, cheaper to type than `const P&`)
- `cross(o, a, b) > 0` means o -> a -> b turns counter-clockwise (b is left of oa)
- polygons are always counter-clockwise (CCW)
- integer coordinates: prefer exact math, `using db = long long;` and `sgn(x)` = `(x > 0) - (x < 0)`.
  cross products reach 4e18 when coords are 1e9, so watch overflow
- output: `cout << fixed << setprecision(10) << ans << "\n";`

## 基础

```cpp
using db = double;
const db eps = 1e-9, PI = acos(-1.0);
int sgn(db x) { return fabs(x) < eps ? 0 : (x < 0 ? -1 : 1); }
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
```

## 点和线

A line or segment is given by two points `a, b`.

```cpp
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
```

Polar sort: CCW starting from the positive x-axis. No `atan2`, so it's exact on integers.

```cpp
int half(P a) { return sgn(a.y) < 0 || (!sgn(a.y) && sgn(a.x) < 0); } // [0, pi) -> 0, [pi, 2pi) -> 1
bool cmpAng(P a, P b) {
    int x = half(a), y = half(b);
    return x != y ? x < y : sgn(det(a, b)) > 0;
}
// sort(all(v), cmpAng); to sort around o, subtract o from every point first
```

## 多边形

```cpp
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
```

## 凸包

Andrew's monotone chain. Returns CCW, no collinear points, starting from the bottom-left point.
To keep collinear points on the hull, change both `<= 0` to `< 0`.

```cpp
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
```

## 旋转卡壳

Diameter (farthest pair). For each edge, the farthest point `j` only moves forward.

```cpp
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
```

Width (min distance between two parallel supporting lines): same loop, start `r = 1e18` and use
`r = min(r, cross(a, b, H[j]) / len(b - a));`

Min-area bounding rectangle: one side lies on a hull edge. Besides the farthest point `j`, keep
`k` (farthest along the edge) and `l` (farthest backwards). All three only move forward.

```cpp
db minRect(vector<P> H) { // H from hull(), n >= 3
    int n = sz(H);
    db res = 1e18;
    for (int i = 0, j = 1, k = 1, l = 0; i < n; ++i) {
        P a = H[i], b = H[(i + 1) % n], e = b - a;
        while(cross(a, b, H[(j + 1) % n]) > cross(a, b, H[j])) j = (j + 1) % n;
        while(dot(e, H[(k + 1) % n] - H[k]) > 0) k = (k + 1) % n;
        if(i == 0) l = j;
        while(dot(e, H[(l + 1) % n] - H[l]) < 0) l = (l + 1) % n;
        db w = cross(a, b, H[j]) / len(e), h = dot(e, H[k] - H[l]) / len(e);
        res = min(res, w * h);
    }
    return res;
}
```

## 半平面交

Each directed line `L(a, b)` keeps its left side. O(n log n).
Always add a big bounding box (4 more lines) first: the code assumes the answer is bounded.

```cpp
struct L {
    P p, v;
    db ang;
    L() {}
    L(P a, P b) : p(a), v(b - a) { ang = atan2(v.y, v.x); }
    bool operator<(const L& b) const { return ang < b.ang; }
};
bool onRight(L l, P a) { return sgn(det(l.v, a - l.p)) < 0; }
P inter(L a, L b) { return lineInter(a.p, a.p + a.v, b.p, b.p + b.v); }
vector<P> halfPlane(vector<L> ls) { // CCW polygon; empty if no area
    sort(all(ls));
    int n = sz(ls), h = 0, t = 0;
    vector<L> q(n);
    vector<P> p(n);
    q[0] = ls[0];
    for (int i = 1; i < n; ++i) {
        while(h < t && onRight(ls[i], p[t - 1])) --t;
        while(h < t && onRight(ls[i], p[h])) ++h;
        if(!sgn(det(ls[i].v, q[t].v))) { // parallel to the last one
            if(dot(ls[i].v, q[t].v) < 0) return {}; // opposite: empty
            if(onRight(q[t], ls[i].p)) continue; // new one is looser
            q[t] = ls[i];
        }
        else q[++t] = ls[i];
        if(h < t) p[t - 1] = inter(q[t - 1], q[t]);
    }
    while(h < t && onRight(q[h], p[t - 1])) --t;
    while(h < t && onRight(q[t], p[h])) ++h;
    if(t - h <= 1) return {};
    p[t] = inter(q[t], q[h]);
    return vector<P>(p.begin() + h, p.begin() + t + 1);
}
```

## 闵可夫斯基和

{a + b}. Start both hulls at their lowest (then leftmost) point and merge the edges by angle.

```cpp
void lowFirst(vector<P>& A) {
    int k = 0;
    for (int i = 1; i < sz(A); ++i)
        if(mp(A[i].y, A[i].x) < mp(A[k].y, A[k].x)) k = i;
    rotate(A.begin(), A.begin() + k, A.end());
}
vector<P> minkowski(vector<P> A, vector<P> B) { // A, B CCW, no collinear points
    lowFirst(A), lowFirst(B);
    int n = sz(A), m = sz(B), i = 0, j = 0;
    vector<P> C = {A[0] + B[0]};
    while(i < n || j < m) {
        P a = A[(i + 1) % n] - A[i % n], b = B[(j + 1) % m] - B[j % m];
        int c = sgn(det(a, b));
        if(j == m || (i < n && c > 0)) C.pb(C.back() + a), ++i;
        else if(i == n || c < 0) C.pb(C.back() + b), ++j;
        else C.pb(C.back() + a + b), ++i, ++j;
    }
    C.pop_back();
    return C;
}
```

Distance between two convex polygons: it equals the distance from the origin to A + (-B).

```cpp
db convexDist(vector<P> A, vector<P> B) { // both CCW, no collinear, n >= 3; 0 if they overlap
    for (auto& p : B) p = p * -1;
    vector<P> C = minkowski(A, B);
    if(inConvex(P(), C)) return 0;
    db r = 1e18;
    for (int i = 0; i < sz(C); ++i) r = min(r, disSeg(P(), C[i], C[(i + 1) % sz(C)]));
    return r;
}
```

## 圆

### 三角形的心 & 最小圆覆盖

```cpp
P circumCenter(P a, P b, P c) { // a, b, c not collinear
    b = b - a, c = c - a;
    db d = 2 * det(b, c);
    return a + P(c.y * dot(b, b) - b.y * dot(c, c), b.x * dot(c, c) - c.x * dot(b, b)) / d;
}
P inCenter(P a, P b, P c) { // weights are the opposite side lengths
    db x = len(b - c), y = len(c - a), z = len(a - b);
    return (a * x + b * y + c * z) / (x + y + z);
}
P orthoCenter(P a, P b, P c) { return a + b + c - circumCenter(a, b, c) * 2; } // H = A + B + C - 2O
pair<P, db> minCircle(vector<P> A) { // randomized incremental, expected O(n)
    shuffle(all(A), mt19937(114514));
    int n = sz(A);
    P o = A[0];
    db r = 0;
    for (int i = 1; i < n; ++i) if(sgn(len(A[i] - o) - r) > 0) {
        o = A[i], r = 0;
        for (int j = 0; j < i; ++j) if(sgn(len(A[j] - o) - r) > 0) {
            o = (A[i] + A[j]) / 2, r = len(A[i] - o);
            for (int k = 0; k < j; ++k) if(sgn(len(A[k] - o) - r) > 0)
                o = circumCenter(A[i], A[j], A[k]), r = len(A[i] - o);
        }
    }
    return {o, r};
}
```

### 交点 & 切线

```cpp
vector<P> lineCircle(P a, P b, P o, db r) { // line ab meets circle (o, r)
    P p = proj(o, a, b), e = (b - a) / len(b - a);
    db d = len(p - o);
    if(sgn(d - r) > 0) return {};
    db h = sqrt(max((db)0, r * r - d * d));
    if(!sgn(h)) return {p};
    return {p - e * h, p + e * h};
}
vector<P> circleCircle(P o1, db r1, P o2, db r2) { // same center returns empty
    db d = len(o2 - o1);
    if(!sgn(d) || sgn(d - r1 - r2) > 0 || sgn(d - fabs(r1 - r2)) < 0) return {};
    db a = (r1 * r1 - r2 * r2 + d * d) / (2 * d), h = sqrt(max((db)0, r1 * r1 - a * a));
    P e = (o2 - o1) / d, p = o1 + e * a;
    if(!sgn(h)) return {p};
    return {p - rot90(e) * h, p + rot90(e) * h};
}
vector<P> tangent(P p, P o, db r) { // touch points of tangents from p
    db d = len(p - o);
    if(sgn(d - r) < 0) return {};
    if(!sgn(d - r)) return {p};
    db t = acos(r / d);
    P e = (p - o) / d * r;
    return {o + rot(e, -t), o + rot(e, t)};
}
vector<pair<P, P>> tangents(P o1, db r1, P o2, db r2) { // outer common tangents; pass -r2 for inner ones
    P d = o2 - o1;
    db dr = r1 - r2, d2 = dot(d, d), h2 = d2 - dr * dr;
    if(!sgn(d2) || sgn(h2) < 0) return {};
    vector<pair<P, P>> res; // (touch point on circle 1, touch point on circle 2)
    for (int s : {-1, 1}) {
        P v = (d * dr + rot90(d) * sqrt(max((db)0, h2)) * s) / d2; // unit normal of the tangent
        res.pb({o1 + v * r1, o2 + v * r2});
    }
    if(!sgn(h2)) res.pop_back();
    return res;
}
```

### 圆与多边形面积交

Split into triangles (center, A[i], A[i+1]) and add their signed areas.

```cpp
db ang(P a, P b) { return atan2(det(a, b), dot(a, b)); } // signed angle from a to b
db triCircle(P p, P q, db r) { // circle at origin, signed area of triangle (0, p, q) inside it
    P d = q - p;
    if(!sgn(len(d))) return 0;
    db a = dot(d, p) / dot(d, d), b = (dot(p, p) - r * r) / dot(d, d), D = a * a - b;
    if(D <= 0) return ang(p, q) * r * r / 2;
    db s = max((db)0, -a - sqrt(D)), t = min((db)1, -a + sqrt(D));
    if(t < 0 || s >= 1) return ang(p, q) * r * r / 2;
    P u = p + d * s, v = p + d * t;
    return (ang(p, u) + ang(v, q)) * r * r / 2 + det(u, v) / 2;
}
db polyCircle(vector<P>& A, P o, db r) { // positive if A is CCW
    db s = 0;
    int n = sz(A);
    for (int i = 0; i < n; ++i) s += triCircle(A[i] - o, A[(i + 1) % n] - o, r);
    return s;
}
```

### 两圆面积交 & 圆的面积并

```cpp
db circleInterArea(P o1, db r1, P o2, db r2) {
    db d = len(o2 - o1);
    if(sgn(d - r1 - r2) >= 0) return 0;
    if(sgn(d - fabs(r1 - r2)) <= 0) return PI * min(r1, r2) * min(r1, r2);
    db a1 = acos((r1 * r1 + d * d - r2 * r2) / (2 * r1 * d)); // half of the central angle
    db a2 = acos((r2 * r2 + d * d - r1 * r1) / (2 * r2 * d));
    return r1 * r1 * (a1 - sin(2 * a1) / 2) + r2 * r2 * (a2 - sin(2 * a2) / 2);
}
```

Union: Green's theorem. Walk every arc not covered by another circle and add
∫(x dy - y dx) / 2 along it. O(n² log n).

```cpp
db circleUnion(vector<P> o, vector<db> r) {
    int n = sz(o);
    db res = 0;
    for (int i = 0; i < n; ++i) {
        vector<pair<db, db>> ev; // covered angle ranges on circle i
        bool inside = false;
        for (int j = 0; j < n; ++j) if(j != i) {
            db d = len(o[j] - o[i]);
            int c = sgn(d + r[i] - r[j]);
            if(c < 0 || (!c && (sgn(d) || j < i))) { inside = true; break; } // i inside j (equal circles: keep one)
            if(sgn(d - r[i] - r[j]) >= 0 || sgn(d + r[j] - r[i]) <= 0) continue; // apart, or j inside i
            db base = atan2(o[j].y - o[i].y, o[j].x - o[i].x);
            db t = acos((r[i] * r[i] + d * d - r[j] * r[j]) / (2 * r[i] * d));
            db a = base - t, b = base + t;
            if(a < -PI) ev.pb({a + 2 * PI, PI}), ev.pb({-PI, b});
            else if(b > PI) ev.pb({a, PI}), ev.pb({-PI, b - 2 * PI});
            else ev.pb({a, b});
        }
        if(inside) continue;
        auto add = [&](db a, db b) { // uncovered arc [a, b]
            res += (r[i] * r[i] * (b - a) + o[i].x * r[i] * (sin(b) - sin(a)) - o[i].y * r[i] * (cos(b) - cos(a))) / 2;
        };
        sort(all(ev));
        db cur = -PI;
        for (auto [a, b] : ev) {
            if(a > cur) add(cur, a);
            cur = max(cur, b);
        }
        if(cur < PI) add(cur, PI);
    }
    return res;
}
```

## 极角扫描

Max number of points a circle of radius r can cover. Some optimal circle has a point A[i] on its boundary.
Put the center at angle θ from A[i]; then A[j] is covered for θ in an interval. Sweep over θ. O(n² log n).

```cpp
int maxCover(vector<P>& A, db r) {
    int n = sz(A), res = 1;
    for (int i = 0; i < n; ++i) {
        vector<pair<db, int>> ev;
        for (int j = 0; j < n; ++j) {
            db d = len(A[j] - A[i]);
            if(j == i || sgn(d - 2 * r) > 0) continue;
            db t = acos(min((db)1, d / (2 * r))), a = atan2(A[j].y - A[i].y, A[j].x - A[i].x) - t;
            if(a < 0) a += 2 * PI;
            ev.pb({a, -1}), ev.pb({a + 2 * t, 1}); // -1 sorts first, so touching counts
            ev.pb({a + 2 * PI, -1}), ev.pb({a + 2 * t + 2 * PI, 1}); // copy for wrap-around
        }
        sort(all(ev));
        int cnt = 1;
        for (auto [x, e] : ev) cnt -= e, res = max(res, cnt);
    }
    return res;
}
```

The same idea (sort the other points by angle around A[i], sweep with two pointers) also gives:
max points on one side of a line through A[i], counting triangles that contain the origin, etc.

## 平面最近点对

Sweep by x, keep a strip of width d in a set ordered by y. O(n log n).

```cpp
db closest(vector<P> A) {
    sort(all(A));
    set<pair<db, int>> S;
    db d = 1e18;
    for (int i = 0, l = 0; i < sz(A); ++i) {
        while(A[i].x - A[l].x > d) S.erase({A[l].y, l}), ++l;
        for (auto it = S.lower_bound({A[i].y - d, -1}); it != S.end() && it->fi < A[i].y + d; ++it)
            d = min(d, len(A[i] - A[it->se]));
        S.insert({A[i].y, i});
    }
    return d;
}
```

## 公式

- Pick: lattice polygon `S = I + B/2 - 1` (I interior points, B boundary points).
  Lattice points on segment (x1,y1)-(x2,y2): `gcd(|x1-x2|, |y1-y2|) + 1`
- Heron: `S = sqrt(p(p-a)(p-b)(p-c))`, `p = (a+b+c)/2`
- Angle between vectors: `acos(dot(a, b) / len(a) / len(b))`; signed: `ang(a, b)`
- Circular segment area: `r^2 / 2 * (theta - sin(theta))`

## 练习题

| 段 | 题 |
| --- | --- |
| 凸包 | P2742 |
| 旋转卡壳 | P1452 |
| 半平面交 | P4196 |
| 闵可夫斯基和 | P4557 |
| 最小圆覆盖 | P1742 |
| 平面最近点对 | P1429 |
| 最小矩形覆盖 | P3187 |
| 两圆面积交 | CF 600D |
| 圆的面积并 | SPOJ CIRU |
| 极角扫描 | POJ 1981 |
