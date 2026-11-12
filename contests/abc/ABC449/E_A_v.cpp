// E - A += v
// https://atcoder.jp/contests/abc449/tasks/abc449_e  (2000 ms, 1024 MB)
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


struct ValueSegTree {
    int n;
    vector<int> tr;

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
    int kth(int p, int l, int r, int k) {
        if (l == r) return l;

        int mid = (l + r) / 2;
        int cnt = tr[p * 2];

        if (k <= cnt)
            return kth(p * 2, l, mid, k);
        else
            return kth(p * 2 + 1, mid + 1, r, k - cnt);
    }

    int kth(int k) {
        if (k < 1 || k > tr[1]) return -1;
        return kth(1, 1, n, k);
    }

    // 查询值域 [1, x] 中有多少个元素
    int countLE(int p, int l, int r, int x) {
        if (r <= x) return tr[p];
        if (l > x) return 0;

        int mid = (l + r) / 2;
        return countLE(p * 2, l, mid, x)
             + countLE(p * 2 + 1, mid + 1, r, x);
    }

    int countLE(int x) {
        return countLE(1, 1, n, x);
    }
};


void solve() {
    int n, m;
    cin >> n >> m;

    vi A(n + 1), freq(m + 1, 0);
    for (int i = 1; i <= n; ++i) {
        cin >> A[i];
        freq[A[i]]++;
    }

    // 按照初始出现次数分组
    int maxf = *max_element(freq.begin() + 1, freq.end());

    vector<vi> bucket(maxf + 1);
    for (int v = 1; v <= m; ++v) {
        bucket[freq[v]].push_back(v);
    }

    int q;
    cin >> q;

    // {查询位置, 原来的查询编号}
    vector<pair<ll, int>> queries(q);
    vi ans(q);

    for (int i = 0; i < q; ++i) {
        cin >> queries[i].first;
        queries[i].second = i;
    }

    sort(all(queries));

    ValueSegTree seg(m);

    ll pos = n;   // 已经处理完的数组长度
    int active = 0;
    int j = 0;    // 当前待回答的查询

    // 第一部分：原始数组
    while (j < q && queries[j].first <= n) {
        ans[queries[j].second] = A[queries[j].first];
        ++j;
    }

    // 第二部分：逐轮激活
    for (int f = 0; f < maxf; ++f) {

        // 这一轮新增可以选择的数
        for (int v : bucket[f]) {
            seg.add(v);
            ++active;
        }

        // 当前轮一共有 active 个数
        ll end = pos + active;

        // 回答属于当前轮的查询
        while (j < q && queries[j].first <= end) {
            ll x = queries[j].first;

            int k = x - pos;
            ans[queries[j].second] = seg.kth(k);

            ++j;
        }

        pos = end;
    }

    // 第三部分：所有数频次相同，开始循环
    while (j < q) {
        ll x = queries[j].first;

        ans[queries[j].second] = (x - pos - 1) % m + 1;
        ++j;
    }

    for (int v : ans) {
        cout << v << '\n';
    }
}


int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int T = 1;
  while (T--) solve();
  return 0;
}
