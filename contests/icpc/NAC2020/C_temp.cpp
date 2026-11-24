#include <bits/stdc++.h>
using namespace std;

using ll = long long;

struct Circle {
    ll x, y, r;
};

struct Arc {
    int id;
    int side;  // -1 下弧，+1 上弧
};

struct Event {
    ll x;
    int id;
    bool entering;

    bool operator<(const Event &other) const {
        // 同一个 x 先删除右端点，再插入左端点。
        return tie(x, entering, id) <
               tie(other.x, other.entering, other.id);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;
    int m = n + q;

    vector<Circle> circles(m);
    vector<Event> events;
    events.reserve(2 * m);

    for (int i = 0; i < m; ++i) {
        auto &[x, y, r] = circles[i];
        cin >> x >> y >> r;
        events.push_back({x - r, i, true});
        events.push_back({x + r, i, false});
    }
    sort(events.begin(), events.end());

    ll sweep_x = 0;
    auto height = [&](Arc arc) {
        const auto &[x, y, r] = circles[arc.id];
        ll dx = sweep_x - x;
        return y + arc.side * sqrtl(r * r - dx * dx);
    };

    auto cmp = [&](Arc a, Arc b) {
        long double ya = height(a), yb = height(b);
        if (ya != yb) return ya < yb;
        // 同一个圆在端点处两条弧同高，仍让下弧排在上弧前面。
        return tie(a.id, a.side) < tie(b.id, b.side);
    };

    set<Arc, decltype(cmp)> active(cmp);
    using Iterator = decltype(active)::iterator;
    vector<Iterator> lower(m), upper(m);

    int root = m;
    vector<int> parent(m, root), order;
    order.reserve(m);

    for (auto [x, u, entering] : events) {
        sweep_x = x;

        if (!entering) {
            active.erase(lower[u]);
            active.erase(upper[u]);
            continue;
        }

        // 新圆左端点处，下弧的高度正好等于圆心的 y。
        auto it = active.lower_bound({u, -1});
        if (it != active.end()) {
            int v = it->id;
            parent[u] = (it->side == 1 ? v : parent[v]);
        }

        lower[u] = active.insert({u, -1}).first;
        upper[u] = active.insert({u, 1}).first;
        order.push_back(u);
    }

    // sum[u][p] 累加的是 u 的所有直接孩子的 dp[v][p]。
    vector<array<int, 2>> sum(m + 1, {0, 0});
    vector<int> answer(q);

    reverse(order.begin(), order.end());
    for (int u : order) {
        auto [a, b] = sum[u];
        int best = max(a, 1 + b);
        int p = parent[u];

        if (u < n) {
            // 原有圆的围栏一直存在。
            sum[p][0] += best;
            sum[p][1] += a;
        } else {
            // 回答自己的询问时保留围栏。
            answer[u - n] = best;

            // 对外传递时去掉围栏，外侧状态直接传到孩子。
            sum[p][0] += a;
            sum[p][1] += b;
        }
    }

    for (int ans : answer) {
        cout << ans << '\n';
    }
}
