#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<int> build_by_complement_blocks(int r) {
    vector<int> a(r + 1, -1);
    // process blocks by their right endpoint R, starting from r and moving left
    stack<int> st;
    st.push(r);
    while (!st.empty()) {
        int R = st.top(); st.pop();
        if (R < 0) continue;
        // find smallest m such that 2^m > R
        int m = 0;
        while ((1 << m) <= R) ++m;
        int mask = (1 << m) - 1;
        int d = mask - R;            // left boundary of this block
        // for i in [d .. R], set a[i] = mask - i
        for (int i = d; i <= R; ++i) {
            a[i] = mask - i;
        }
        // remaining part is [0 .. d-1]
        if (d - 1 >= 0) st.push(d - 1);
    }
    return a;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        int l, r;
        cin >> l >> r;
        // Easy version guarantee: l == 0
        if (l != 0) {
            // fallback: the easy version should have l==0; if not, we can still
            // handle it by shifting only for constructing the permutation but
            // note OR sums do not commute with shifting. If you need the
            // general (l != 0) version, tell me and I'll provide that.
        }
        vector<int> a = build_by_complement_blocks(r);
        ll total = 0;
        for (int i = 0; i <= r; ++i) total += (ll)(i | a[i]);
        cout << total << '\n';
        for (int i = 0; i <= r; ++i) {
            cout << a[i] << (i == r ? '\n' : ' ');
        }
    }
    return 0;
}
