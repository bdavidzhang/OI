#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct Node {
    ll sum;
    ll minPref;
    Node(ll s=0, ll m=0): sum(s), minPref(m) {}
};

struct SegTree {
    int n;
    vector<Node> st;
    SegTree(int _n=0) { init(_n); }
    void init(int _n) {
        n = _n;
        st.assign(4*(n+1), Node());
    }
    static Node merge(const Node &L, const Node &R) {
        Node res;
        res.sum = L.sum + R.sum;
        res.minPref = min(L.minPref, L.sum + R.minPref);
        return res;
    }
    void build(int p, int l, int r, const vector<ll> &arr) {
        if (l == r) {
            st[p].sum = arr[l];
            st[p].minPref = arr[l];
            return;
        }
        int mid = (l + r) >> 1;
        build(p<<1, l, mid, arr);
        build(p<<1|1, mid+1, r, arr);
        st[p] = merge(st[p<<1], st[p<<1|1]);
    }
    void build(const vector<ll> &arr) {
        build(1, 0, n, arr);
    }
    void update(int p, int l, int r, int idx, ll delta) {
        if (l == r) {
            st[p].sum += delta;
            st[p].minPref += delta;
            return;
        }
        int mid = (l + r) >> 1;
        if (idx <= mid) update(p<<1, l, mid, idx, delta);
        else update(p<<1|1, mid+1, r, idx, delta);
        st[p] = merge(st[p<<1], st[p<<1|1]);
    }
    void update(int idx, ll delta) { 
        update(1, 0, n, idx, delta);
    }
    int findFirstPrefixLE(ll target) {
        int p = 1, l = 0, r = n;
        ll cur = 0;
        if (st[1].minPref > target) return -1; 
        while (l < r) {
            int mid = (l + r) >> 1;
            Node &L = st[p<<1];
            if (L.minPref + cur <= target) {
                p = p<<1;
                r = mid;
            } else {
                cur += L.sum;
                p = p<<1|1;
                l = mid + 1;
            }
        }
        return l;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int ac, dr;
    if (!(cin >> ac >> dr)) return 0;
    int n; cin >> n;
    vector<int> a(n), d(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n; ++i) cin >> d[i];
    int m; cin >> m;

    vector<int> curDelta(n);
    vector<int> freq(n+1, 0);
    for (int i = 0; i < n; ++i) {
        int ra = max(a[i] - ac, 0);
        int rd = max(d[i] - dr, 0);
        ll raw = (ll)ra + (ll)rd;
        int idx = (raw <= n ? (int)raw : n+1);
        curDelta[i] = idx;
        if (idx <= n) freq[idx] ++;
    }

    // val[x] = freq[x] - 1 for x in [0..n]
    vector<ll> val(n+1);
    for (int i = 0; i <= n; ++i) val[i] = (ll)freq[i] - 1LL;

    SegTree st(n);
    st.build(val);

    for (int qi = 0; qi < m; ++qi) {
        int k, na, nd;
        cin >> k >> na >> nd;
        --k; 

        int oldIdx = curDelta[k];
        if (oldIdx <= n) {
            st.update(oldIdx, -1);
        }

        int ra = max(na - ac, 0);
        int rd = max(nd - dr, 0);
        ll raw = (ll)ra + (ll)rd;
        int newIdx = (raw <= n ? (int)raw : n+1);
        curDelta[k] = newIdx;
        if (newIdx <= n) {
            st.update(newIdx, +1);
        }


        int pos = st.findFirstPrefixLE(-1);
        if (pos == -1) pos = n; 

        cout << pos << '\n';
    }

    return 0;
}
