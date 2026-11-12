// F - Email Scheduling Optimization
// https://atcoder.jp/contests/abc467/tasks/abc467_f  (2000 ms, 1024 MB)
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vll = vector<ll>;
using vpii = vector<pii>;
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()
#define pb push_back

const int MAXN = 2e5 + 20;
ll A[MAXN], B[MAXN];
vector<ll> S,vals;

struct Node{
  ll tot = 0;
  ll best = 0;
};

Node T[MAXN << 2];

struct Query{
  int t,i,x;
};


void pu(int rt ){
  Node L = T[rt << 1];
  Node R = T[rt << 1 | 1];
  T[rt].tot = L.tot + R.tot;
  T[rt].best = max(L.best, R.best + L.tot);
}

void build(int rt, int l, int r){
  if(l == r){
    T[rt].tot = S[l];
    T[rt].best = (S[l] == 0) ? 0 : S[l] + vals[l];
    return;
  }
  int L = rt << 1; 
  int R = rt << 1 | 1;

  int mid = (l + r) >> 1;

  build(L,l,mid);
  build(R,mid+1,r);
  pu(rt);
}

void upd(int rt, int l, int r, int pos, ll c){
  if(l == r){
    T[rt].tot += c;
    T[rt].best = (T[rt].tot == 0) ? 0 : T[rt].tot + vals[l];
    return;
  }
  int L = rt << 1;
  int R = rt << 1 | 1;
  int mid = (l + r) >> 1;

  if(pos <= mid) upd(L,l,mid,pos,c);
  else upd(R,mid+1,r,pos,c);

  pu(rt);
}


void solve(){
  int n,q;
  cin >> n >> q;
  for(int i = 1; i <= n; ++i) cin >> A[i];
  for(int i = 1; i <= n; ++i){cin >> B[i]; vals.pb(B[i]);}
  vector<Query> qs(q);
  for(int j = 0; j < q; ++j){
    cin >> qs[j].t >> qs[j].i >> qs[j].x;
    if(qs[j].t == 2) vals.pb(qs[j].x);
  }

  sort(all(vals),greater<int>());
  vals.erase(unique(all(vals)),vals.end());

  int K = sz(vals);
  S.assign(K+1,0);

  auto getpos = [&](ll b){
    return lower_bound(all(vals),b,greater<int>()) - vals.begin();
  };
  
  for(int i = 1; i <= n; ++i){
    S[getpos(B[i])] += A[i];
  }
  //cout << endl;

  build(1,0,K-1);

  //for(auto x : S) cout << x << " ";
  //cout << endl;


  for(int j = 0; j < q; ++j){
    auto [t,i,x] = qs[j];
    if(t == 1){
      ll delta = x - A[i];
      ll pos = getpos(B[i]);
      upd(1,0,K-1,pos,delta);
      A[i] = x;
    }else if(t == 2){
      ll prev = getpos(B[i]);
      ll cur = getpos(x);
      upd(1,0,K-1,prev,-A[i]);
      upd(1,0,K-1,cur,A[i]);

      B[i] = x;
    }
    cout << T[1].best << '\n';
  }

}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int T = 1;
  while (T--) solve();
  return 0;
}


