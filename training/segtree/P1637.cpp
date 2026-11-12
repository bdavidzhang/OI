// P1637 三元上升子序列
// https://www.luogu.com.cn/problem/P1637  (1000 ms, 128 MB)
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


struct Node {
    ll cnt1 = 0, cnt2 = 0, cnt3 = 0;

    Node operator+(const Node& b) const {
        return {
            cnt1 + b.cnt1,
            cnt2 + b.cnt2,
            cnt3 + b.cnt3
        };
    }
};

struct ValueSegTree {
    int n;
    vector<Node> tr;

    ValueSegTree(int n) : n(n), tr(4 * n + 4) {}

    void update(int p, int l, int r, int x, Node v) {
        tr[p] = tr[p] + v;
        if (l == r) return;

        int mid = (l + r) / 2;
        if (x <= mid)
            update(p * 2, l, mid, x, v);
        else
            update(p * 2 + 1, mid + 1, r, x, v);
    }

    void add(int x, Node v) {
        update(1, 1, n, x, v);
    }

    Node query(int p, int l, int r, int ql, int qr) {
        if (qr < l || r < ql) return {};
        if (ql <= l && r <= qr) return tr[p];

        int mid = (l + r) / 2;
        return query(p * 2, l, mid, ql, qr)
             + query(p * 2 + 1, mid + 1, r, ql, qr);
    }

    Node query(int l, int r) {
        if (l > r) return {};
        return query(1, 1, n, l, r);
    }
};

void solve() {
  int n;
  cin >> n;
  vector<ll> a(n);
  for(int i = 0; i < n; ++i)cin >> a[i];
  
  vector<ll> v = a;
  sort(all(v));
  v.erase(unique(all(v)),v.end());

  auto getpos = [&](ll x){
    return lower_bound(all(v),x) - v.begin() + 1;
  };

  ll V = sz(v);
  ValueSegTree vs(V);

  ll ans = 0;
  for(int i = 0; i < n; ++i){
    ll x = a[i];
    ll idx = getpos(x);
    Node rs = vs.query(1,idx-1);
    Node cur; 
    cur.cnt1 = 1;
    cur.cnt2 = rs.cnt1;
    cur.cnt3 = rs.cnt2;

    vs.add(idx,cur);
  }
  ans = vs.tr[1].cnt3;
  cout << ans << endl;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int T = 1;
  while (T--) solve();
  return 0;
}
