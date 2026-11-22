// Plan Holidays
// https://atcoder.jp/contests/abc456/tasks/abc456_f  (2000 ms, 1024 MB)
#include <bits/stdc++.h>
#include <climits>
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
#define endl '\n'

constexpr int MAXN = 2e5+10;
constexpr ll INF = 1e18;

ll A[MAXN];

struct Node{
  ll f[2][2];
  Node(){
    for(int x = 0; x < 2; ++x)
      for(int y = 0; y < 2; ++y)
        f[x][y] = INF; //fxy -> left status x, right status y (paid)
  }
};

Node T[MAXN << 2];

Node merge(const Node& L, const Node &R){
  Node res;
  for (int x = 0; x < 2; ++x) {
    for(int y = 0; y < 2; ++y){
      for(int b = 0; b < 2; ++b){
        for(int c = 0; c < 2; ++c){
          if(b ==0 && c == 0) continue;
          res.f[x][y] = min(res.f[x][y],L.f[x][b]+R.f[c][y]);
        }
      }
    }
  }
  return res;
}

void pu(int rt){
  T[rt] = merge(T[rt << 1], T[rt << 1 | 1]);
}

void build(int rt, int l, int r){
  if(l == r){
    T[rt] = Node();
    T[rt].f[0][0] = 0;
    T[rt].f[1][1] = A[l];
    return;
  }

  int m = l +r >> 1;
  build(rt << 1, l, m);
  build(rt << 1 | 1, m+1, r);
  pu(rt);
}

void upd(int rt, int l, int r, int L, int R, int c){

}

Node que(int rt, int l, int r, int L, int R){
  if(L <= l && R >= r) return T[rt];

  int m = l + r >> 1;

  if(R <= m) return que(rt << 1, l, m, L, R); 
  if(L > m) return que(rt << 1 | 1, m+1, r, L, R);

  Node Le = que(rt << 1, l, m, L, R);
  Node Rt = que(rt << 1 | 1, m+1, r, L,R);
  return merge(Le,Rt);
}

void solve() {
  int n, k;
  cin >> n >> k;
  for(int i = 1; i <= n; ++i) cin >> A[i];
  build(1,1,n);

  ll ans = INF;
  for(int x : {k, k+1}){
    for(int l = 1; l + x -1 <= n; ++l){
      int r = l + x - 1;
      Node cur = que(1,1,n,l,r);
      ans = min(ans, cur.f[1][1]);
    }
  }
  cout << ans << endl;

}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int TT = 1;
  cin >> TT;
  while (TT--) solve();
  return 0;
}
