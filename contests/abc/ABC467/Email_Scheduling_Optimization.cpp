#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
#define all(x) (x).begin(), (x).end()

const int MAXN = 2e5+10;
vector<ll> S, vals;
struct node{
  ll sum;
  ll best;
};

node T[MAXN << 2] , tg[MAXN << 2];
void pu( int rt ) { 
  node L = T[rt<<1];
  node R = T[rt << 1 | 1];
  ll tot = L.sum + R.sum;
  ll mybest = min(L.best, L.sum + R.best);
  T[rt] = {tot,mybest}; 
}

void build( int rt , int l , int r ) {
if (l == r) {
      T[rt].sum = S[l];
      T[rt].best = (S[l] == 0 ? 0 : S[l] + vals[l]);
      return;
  }
  int m = (l + r) >> 1;
  build(rt << 1, l, m);
  build(rt << 1 | 1, m + 1, r);
  pu(rt);
}
void upd( int rt , int l , int r , int pos, ll delta) {
	if (l == r) {
      T[rt].sum += delta;
      T[rt].best =
          (T[rt].sum == 0 ? 0 : T[rt].sum + vals[l]);
      return;
    }
    int m = (l + r) >> 1;
    if (pos <= m)
        upd(rt << 1, l, m, pos, delta);
    else
        upd(rt << 1 | 1, m + 1, r, pos, delta);
    pu(rt);
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;

   
}



