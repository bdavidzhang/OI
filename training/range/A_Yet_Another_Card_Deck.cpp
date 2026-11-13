// A. Yet Another Card Deck
// https://codeforces.com/group/tKC7z9Nm0A/contest/732255/problem/A  (2000 ms, 256 MB)
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
#define endl '\n'


const int MAXN = 6e5+10;
int A[MAXN];
int T[MAXN << 2];

void pu(int rt){ T[rt] = T[rt << 1] + T[rt << 1 | 1];}

void build(int rt, int l, int r){
  if(l == r){
    T[rt] = A[l];
    return;
  }
  int m = l + r >> 1;
  build(rt << 1, l, m);
  build(rt << 1 | 1, m+1, r);
  pu(rt);
}


void upd(int rt, int l, int r, int L, int R, int c){
  if(l == r){ T[rt] = c; return;}
  int m = l + r >> 1;
  if(L <= m) upd(rt << 1, l, m, L, R, c);
  if(R > m) upd(rt << 1 | 1, m+1, r, L, R, c);
  pu(rt);
}

int que(int rt, int l, int r, int L, int R){
  if(L <= l && R >= r) return T[rt];
  int m = l + r >> 1;
  ll tot = 0;
  if(L <= m) tot += que(rt << 1, l, m, L, R);
  if(R > m) tot += que(rt << 1 | 1, m + 1, r, L, R);
  return tot;
}


void solve(){
  int n, q;
  cin >> n >> q;
  map<int,int> val;
  map<int,set<int>> pos;
  for(int i = 1; i <= n; ++i){
    int x;
    cin >> x;
    val[i+q] = x;
    pos[x].insert(i+q);
    A[i+q] = 1;
  }
  int front = q;
  build(1,1,n+q);

//  for(auto &[k, v] : val){
//    cout << k << " " << v << endl;
// }
//
//  for(auto &[k, v] : pos){
//    cout << k << " " << *v.begin() << endl;
// }
//  
  for(int i = 0; i < q; ++i){
    int t;
    cin >> t; 
    int p = *pos[t].begin();
    cout << que(1,1,n+q,1,p) << " ";
    pos[t].erase(p);
    pos[t].insert(front);
    val.erase(p);
    val[front] = t;
    //cout << endl;
    //for(int j = 1; j <= n + q; ++j) cout << A[j] << " ";
    //cout << endl;
    upd(1,1,n+q,p,p,0);
    upd(1,1,n+q,front,front,1);
    front--;
  }
  cout << endl;

}


int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int T = 1;
  while (T--) solve();
  return 0;
}
