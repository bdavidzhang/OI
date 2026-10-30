#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll INF = (1LL<<60);

map<char,int> colToInt = {
    {'B',0},
    {'G',1},
    {'R',2},
    {'Y',3},
};

using t4 = array<ll,4>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin >> T;
    while (T--) {
        int n,q;
        cin >> n >> q;
        vector<pair<int,int>> a(n);
        for (auto &x : a) {
            string s; cin >> s;
            x.first = colToInt[s[0]];
            x.second = colToInt[s[1]];
        }

        vector<t4> pvr(n, t4{-1,-1,-1,-1});
        vector<t4> nxt(n, t4{n,n,n,n});

        // build pvr
        t4 near = {-1,-1,-1,-1};
        for (int j=0;j<n;j++) {
            auto [c1,c2] = a[j];
            int p1 = near[c1], p2 = near[c2];
            pvr[j][c1] = pvr[j][c2] = j;
            for (int col=0;col<4;col++) {
                if (p1 != -1) pvr[j][col] = max(pvr[j][col], pvr[p1][col]);
                if (p2 != -1) pvr[j][col] = max(pvr[j][col], pvr[p2][col]);
            }
            near[c1] = near[c2] = j;
        }

        // build nxt
        near = {n,n,n,n};
        for (int j=n-1;j>=0;j--) {
            auto [c1,c2] = a[j];
            int p1 = near[c1], p2 = near[c2];
            nxt[j][c1] = nxt[j][c2] = j;
            for (int col=0;col<4;col++) {
                if (p1 != n) nxt[j][col] = min(nxt[j][col], nxt[p1][col]);
                if (p2 != n) nxt[j][col] = min(nxt[j][col], nxt[p2][col]);
            }
            near[c1] = near[c2] = j;
        }

        auto dist = [&](int x, int px, int py, int y) -> ll {
            if (px == -1 || px == n) return INF;
            if (py == -1 || py == n) return INF;
            return abs(px - x) + abs(px - py) + abs(y - py);
        };

        while (q--) {
            int x,y; cin >> x >> y;
            x--; y--;
            if (x > y) swap(x,y);

            ll ans = INF;
            for (int j=0;j<4;j++) {
                ans = min(ans, dist(x, pvr[x][j], pvr[y][j], y));
                ans = min(ans, dist(x, pvr[x][j], nxt[y][j], y));
                ans = min(ans, dist(x, nxt[x][j], pvr[y][j], y));
                ans = min(ans, dist(x, nxt[x][j], nxt[y][j], y));
            }
            if (ans > 2*n) ans = -1;
            cout << ans << "\n";
        }
    }
    return 0;
}
