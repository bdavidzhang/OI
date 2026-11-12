// P1908 逆序对
// https://www.luogu.com.cn/problem/P1908  (1000 ms, 1024 MB)
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

const int MAXN = 5e5 + 10;


struct ValueSegTree {
    int n;
    vector<ll> tr;

    ValueSegTree(int n) : n(n), tr(4 * n + 4, 0) {}

    // 在值域中的 x 处增加 delta 个元素
    void update(int p, int l, int r, int x, int delta) {
        tr[p] += delta;
        if (l == r) return;

        int mid = (l + r) / 2;
        if (x <= mid)
            update(p * 2, l, mid, x, delta);
        else
            update(p * 2 + 1, mid + 1, r, x, delta);
    }

    void add(int x, int delta = 1) {
        update(1, 1, n, x, delta);
    }

    // 查询第 k 小，k 从 1 开始
    ll kth(int p, int l, int r, int k) {
        if (l == r) return l;

        int mid = (l + r) / 2;
        int cnt = tr[p * 2];

        if (k <= cnt)
            return kth(p * 2, l, mid, k);
        else
            return kth(p * 2 + 1, mid + 1, r, k - cnt);
    }

    ll kth(int k) {
        if (k < 1 || k > tr[1]) return -1;
        return kth(1, 1, n, k);
    }

    // 查询值域 [1, x] 中有多少个元素
    ll countLE(int p, int l, int r, int x) {
        if (r <= x) return tr[p];
        if (l > x) return 0;

        int mid = (l + r) / 2;
        return countLE(p * 2, l, mid, x)
             + countLE(p * 2 + 1, mid + 1, r, x);
    }

    ll countLE(int x) {
        return countLE(1, 1, n, x);
    }
};


void solve() {
  int n;
  cin >> n;
  vector<ll> a(n);
  for(int i = 0 ;i < n; ++i){
    cin >> a[i];
  }


 
  vector<ll> vals = a;
  sort(all(vals));
  vals.erase(unique(all(vals)),vals.end());

  auto getrank = [&](ll b){
    return lower_bound(all(vals),b) - vals.begin() + 1;
  };
  
  ll V = sz(vals);
  ValueSegTree vs(V);
  ll ans = 0;
  for(int i = 0; i < n; ++i){
    ll x = a[i]; 
    int idx = getrank(x);
    ans += i - vs.countLE(idx); 
    vs.add(idx);
  }
  cout << ans << endl;

}


int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int T = 1;
  while (T--) solve();
  return 0;
}
