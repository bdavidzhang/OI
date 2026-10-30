//self implemented template

#include<bits/stdc++.h>
using namespace std;


#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

using ll = long long;

ll gcd(ll a, ll b){
    if(b > a) swap(a,b);
    if(b == 0) return a;
    return gcd(b,a % b);
}

//handles fracs up to all precision
struct Frac {
    ll n,d;
    Frac(ll nn = 0, ll dd = 1) : n(nn), d(dd){
        reduce();
    }//takes in input and reduces to gcd = 1

    void reduce(){
        assert(d);
        ll g = gcd(abs(n),abs(d));
        n /= g; 
        d /= g;
        if (d < 0) {d = -d; n = -n;}
        //make sure denom is always > 0
    }

    Frac operator+(Frac rhs) const {
        return Frac(n*rhs.d + d*rhs.n, d * rhs.d);
    }
    Frac operator-(Frac rhs) const{
        return Frac(n*rhs.d - d*rhs.n, d*rhs.d);
    }
    Frac operator*(Frac rhs) const{
        return Frac(n*rhs.n,d*rhs.d);
    }
    Frac operator/(Frac rhs) const{
        return Frac(n*rhs.d,d*rhs.n);
    }
    bool operator<(Frac rhs) const{
        return (n*rhs.d < d*rhs.n);
    }
    friend ostream& operator<<(ostream& out, Frac f){
        return out << f.n << '/' <<f.d;
    }//for printing
};

struct P{
    Frac x,y;

    P operator+(P rhs) const { return P(x+rhs.x,y+rhs.y);}
    P operator-(P rhs) const { return P(x-rhs.x,y-rhs.y);}

    Frac cross(P rhs) const { return x * rhs.y - y * rhs.x;}//using 3d coordinates 
    Frac dot(P rhs) const { return x * rhs.x + y * rhs.y; }
    Frac cross(P a, P b) const { return (a-*this).cross(b-*this);} //cross a \times b with origin at cur point
};

//shoelace formula
Frac area_poly(const vector<P> p){
    Frac a;
    for(int i = 0, j = p.size() - 1; i < p.size(); j = i++){
        a = a + p[j].cross(p[i]);
    }
    
    return a*Frac(1,2);
}

int sgn(Frac x){
    return (x.n > 0) - (x.n < 0); 
    //1 if x > 0, 0 if x = 0, -1 if x < 0
}
int sideOf(P s, P e, P p){
    return sgn(s.cross(e,p));
}//determines which side of the polygon you are on? 

Frac rat(P a, P b) { return sgn(b.x) ? a.x/b.x : a.y/b.y; }
Frac polyUnion(const vector<vector<P>>& poly) {
	Frac ret = 0;
	rep(i,0,sz(poly)) rep(v,0,sz(poly[i])) {
		P A = poly[i][v], B = poly[i][(v + 1) % sz(poly[i])];
		vector<pair<Frac, int>> segs = {{Frac(0), 0}, {Frac(1), 0}};
		rep(j,0,sz(poly)) if (i != j) {
			rep(u,0,sz(poly[j])) {
				P C = poly[j][u], D = poly[j][(u + 1) % sz(poly[j])];
				int sc = sideOf(A, B, C), sd = sideOf(A, B, D);
				if (sc != sd) {
					Frac sa = C.cross(D, A), sb = C.cross(D, B);
					if (min(sc, sd) < 0)
						segs.emplace_back(sa / (sa - sb), sgn(sc - sd));
				} else if (!sc && !sd && j<i && sgn((B-A).dot(D-C))>0){
					segs.emplace_back(rat(C - A, B - A), 1);
					segs.emplace_back(rat(D - A, B - A), -1);
				}
			}
		}
		sort(all(segs));
		for (auto& s : segs) s.first = min(max(s.first, Frac(0)), Frac(1));
		Frac sum = 0;
		int cnt = segs[0].second;
		rep(j,1,sz(segs)) {
			if (!cnt) sum = sum + segs[j].first - segs[j - 1].first;
			cnt += segs[j].second;
		}
		ret = ret + A.cross(B) * sum;
	}
	return ret / 2;
}


int main(){
    
    int n,q;
    cin >> n >> q;
    
    vector<P> points(n);
    for(P& p: points){
        ll x,y;
        cin >> x >> y;
        p = {Frac(x), Frac(y)};
    }

    Frac area = area_poly(points);

    Frac half(1,2), nhalf(-1,2);
    //the points need to be rendered in clockwise order for 
    //area formula to work

    vector<P> square_basic = {{half,half},{nhalf,half},{nhalf,nhalf},{half,nhalf}};

    
    while(q--){
        ll x,y;
        cin >> x >> y;
        P center = {Frac(x),Frac(y)}; //we can always shift the coordinate system so that 
        // the input coordinate is the center of the pixel

        vector<P> square(4);
        for(int i = 0; i < 4; ++i) square[i] = square_basic[i] + center;

        Frac ans = area + Frac(1) - polyUnion({points, square});
        cout << ans << endl;
    }
    return 0;
}