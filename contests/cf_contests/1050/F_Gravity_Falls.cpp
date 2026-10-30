#include <bits/stdc++.h>
using namespace std;

struct SA {
    vector<int> sa, rk;
    void build(vector<int>& s) {
        int n = s.size();
        sa.resize(n); rk.resize(n);
        iota(sa.begin(), sa.end(), 0);
        for (int i = 0; i < n; i++) rk[i] = s[i];
        for (int k = 1; k < n; k <<= 1) {
            auto cmp = [&](int i, int j) {
                if (rk[i] != rk[j]) return rk[i] < rk[j];
                int ri = i + k < n ? rk[i + k] : -1;
                int rj = j + k < n ? rk[j + k] : -1;
                return ri < rj;
            };
            sort(sa.begin(), sa.end(), cmp);
            vector<int> nr(n);
            nr[sa[0]] = 0;
            for (int i = 1; i < n; i++) 
                nr[sa[i]] = nr[sa[i - 1]] + cmp(sa[i - 1], sa[i]);
            rk = nr;
            if (rk[sa[n - 1]] == n - 1) break;
        }
    }
} SA;

void solve() {
    int n; cin >> n;
    vector<vector<int>> a(n);
    vector<int> all, pos(n), len(n);
    for (int i = 0; i < n; i++) {
        cin >> len[i]; a[i].resize(len[i]);
        pos[i] = all.size();
        for (int j = 0; j < len[i]; j++) {
            cin >> a[i][j]; all.push_back(a[i][j]);
        }
        all.push_back(0); // delimiter
    }
    for (int &x : all) x++;
    SA.build(all);
    auto& rk = SA.rk;

    vector<int> res;
    vector<int> used(n, 0);
    int cur = 0, cnt = 0;
    while (cnt < n) {
        int best = -1;
        for (int i = 0; i < n; i++) if (!used[i] && len[i] > cur) {
            if (best == -1 || rk[pos[i] + cur] < rk[pos[best] + cur]) best = i;
        }
        if (best == -1) break;
        for (int i = cur; i < len[best]; i++) res.push_back(a[best][i]);
        cur = len[best]; used[best] = 1; cnt++;
    }
    for (int i = 0; i < (int)res.size(); i++) cout << res[i] << " \n"[i + 1 == (int)res.size()];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; 
    cin >> t;
    while (t--){
        solve();
    }
}
