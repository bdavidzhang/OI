#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
struct P {ll x, y;};

ll cross(const P& o, const P& a, const P& b){
  return (a.x - o.x) * (b.y - o.y) - (a.y - o.y) * (b.x - o.x);
}
ll dist2(const P& a, const P& b){
  ll dx = a.x - b.x, dy = a.y - b.y;
  return dx * dx + dy * dy;
}

pair<ll, int> diameter(const vector<P> &p ){
  int n = p.size();
  ll best = 0;
  set<pair<int,int>> pairs; 
  auto check = [&](int a, int b){
    if (a == b) return;
    ll d = dist2(p[a],p[b]);
    if(d > best){
      best = d;
      pairs.clear();
    }
    if(d == best) pairs.insert({min(a,b),max(a,b)});
  };
  int j = 1;
  for (int i =0 ; i < n; ++i){
    int ni = (i+1) % n;
    while (cross(p[i], p[ni], p[(j+1)%n]) > cross(p[i],p[ni],p[j])){
      j = (j+1) % n;
    }
    check(i,j); check(ni,j);
    int nj = (j+1) % n;
    if (cross(p[i],p[ni],p[nj]) == cross(p[i],p[ni],p[j])) {
      check(i,nj);
      check(ni,nj);
    }
  }
  int cnt = 0;
  for (auto [a,b] : pairs){
    if (b - a != 1){
      if (!(a == 0 && b == n-1)) cnt++;
    }
  }
  return {best,cnt};
}

void solve(){
  ll n,k;
  cin >> n >> k;
  vector<P> vp(n);
  for(int i = 0;i < n; ++i){
    ll a, b; cin >> a >> b;
    vp[i].x = a; vp[i].y = b;
  }

  ll D2; 
  int g;
  auto res = diameter(vp);
  D2 = res.first;
  g = res.second;

  auto check = [&](ll c){
    __int128_t LHS = 4 * c * c * D2; //not a prob with check then 
    __int128_t RHS = k * k;
    return LHS == RHS;
  };
  ll c = ceil(k / (2.0 * sqrt((long double) D2))); //checking here 
  //LETS GOOOOOOOOOOOOOOOOO 
  bool eq = check(c);
  ll ans = 0;
  if(eq){
    if(c <= g) ans = c; 
    else ans = c+1;
  }else{
    ans = c; 
  }

  cout << ans << '\n';
  //the main idea is that for the diagonal D of the polygon
  //each cut increases tot by 2D 
  //so after c cuts -> 2cD 
  //each cut is not *exactly* D, but arbitrary D' < D
  //so we consider c such that 2cD > k 
  //in this case c = ceil(k / (2D))
  //but it is also possible for 2cD = k
  //sqauring -> 4 * c^2 * D^2 = k^2
  //if there are more pairs than c, then it is possible for all
  //these cuts to be exactly D
  //then we can just go 
  //otherwise we need ans = c+1


}


int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  solve();
  return 0;
}