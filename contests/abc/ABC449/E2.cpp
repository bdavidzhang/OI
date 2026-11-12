#include<bits/stdc++.h>
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
#define fi first
#define se second
#define pb push_back

struct SegTree{
  int n;
  vi tr;
  
  SegTree(int n) : n(n), tr(4*n+4,0) {}

  void upd(int p, int l, int r, int x, int d){
    tr[p] += d;
    if (l == r) return ;
    int m = (l + r) >> 1;
    if(x <= m) upd(p << 1, l, m, x,d);
    else upd(p << 1 | 1,m+1,r,x,d);
  }
  
  void add(int x, int d = 1){upd(1,1,n,x,d);}

  int kth(int p, int l, int r, int k){
    if(l== r) return l;
    int m = (l+r) >> 1;
    int cnt = tr[p*2];

    if(k <= cnt) return kth(p << 1, l, m, k);
    else return kth(p << 1 | 1, m + 1, r, k - cnt);
  }

  int kth(int k){
    if(k < 1 || k > tr[1]) return -1;
    return kth(1,1,n,k);
  }

  int countLE(int p, int l, int r, int x){
    if (r <= x) return tr[p];
    if(l > x) return 0;
    int m = (l + r) >> 1;
    return countLE(p << 1, l, m, x) + countLE(p << 1 | 1, m+1, r, x);
  }

  int countLE(int x){return countLE(1,1,n,x);} 
};


void solve(){
  int n,m;
  cin >> n >> m;
  
  vi A(n+1), fre(m+1,0);
  for(int i = 1; i <= n; ++i){
    cin >> A[i];
    fre[A[i]]++;
  }

  ll maxf = *max_element(all(fre));
  vector<int> bucket(maxf+1);
  for(int i = 1; i <= m; ++i){
    bucket[fre[i]].push_back(i); 
  }
  
  int q;
  cin >> q;

  vector<pair<ll,int>> qs(q);
  vi ans(q);

  for(int i = 0; i < q; ++i){
    cin >> qs[i].fi;
    qs[i].se = i;
  }

  sort(all(qs));
  SegTree seg(m);

  int pos = n;
  int j = 0;
  int act = 0; 
  
  while(j < q && qs[j].fi <= n){
    ans[qs[j].se] = A[qs[j].fi];
    j++;
  }

  for(int f = 0; f <= maxf; ++f){
    
    for(int v : bucket[f]){
      seg.add(v);
      act++;
    }

    ll end = act + pos;
    while(j < q && qs[j].fi <= end){
      ll x = qs[j].fi - pos;
      ans[qs[j].se] = seg.kth(x);
      j++;
    }
    pos = end;
  }

  while(j < q){
    ll x = qs[j].fi;
    ans[qs[j].se] = (x - end) % n + 1;
  } 
  
  for(auto v : ans) cout << v << '\n';
}



int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  solve();


  return 0;
}
