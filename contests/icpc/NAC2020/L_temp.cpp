#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<string> grid(n);
    for (auto &row : grid) cin >> row;

    vector id(n, vector<int>(m, -1));
    vector<pair<int, int>> pos;

    for (int r = 0; r < n; ++r) {
        for (int c = 0; c < m; ++c) {
            if (grid[r][c] == 'V' || grid[r][c] == 'H') {
                id[r][c] = pos.size();
                pos.emplace_back(r, c);
            }
        }
    }

    int k = pos.size();
    vector<vector<pair<int, int>>> adj(k);
    vector<int> forced(k, -1);

    // 0 = 上，1 = 右，2 = 下，3 = 左
    constexpr int dr[] = {-1, 0, 1, 0};
    constexpr int dc[] = {0, 1, 0, -1};

    auto has_face = [](char statue, int side) -> int {
        return (side % 2 == 0) == (statue == 'V');
    };

    for (int u = 0; u < k; ++u) {
        auto [sr, sc] = pos[u];

        for (int side = 0; side < 4; ++side) {
            int r = sr, c = sc, dir = side;
            int start_face = has_face(grid[sr][sc], side);

            while (true) {
                int nr = r + dr[dir];
                int nc = c + dc[dir];

                if (nr < 0 || nr >= n || nc < 0 || nc >= m) {
                    // 撞墙后反向进入刚离开的格子。
                    nr = r;
                    nc = c;
                    dir ^= 2;
                }

                r = nr;
                c = nc;

                char cell = grid[r][c];
                if (cell == '#') {
                    // 旋转后的出发侧必须没脸。
                    if (forced[u] != -1 && forced[u] != start_face) {
                        cout << -1 << '\n';
                        return 0;
                    }
                    forced[u] = start_face;
                    break;
                }

                int v = id[r][c];
                if (v != -1) {
                    int end_face = has_face(cell, dir ^ 2);
                    // 反向追踪同一条光路时会加入反向边。
                    adj[u].emplace_back(v, start_face ^ end_face);
                    break;
                }

                if (cell == '/') {
                    dir ^= 1;
                } else if (cell == '\\') {
                    dir ^= 3;
                }
            }
        }
    }

    vector<int> value(k, -1);
    int answer = 0;

    for (int root = 0; root < k; ++root) {
        if (value[root] != -1) continue;

        queue<int> q;
        q.push(root);
        value[root] = 0;

        int size = 0, ones = 0;
        bool valid[2] = {true, true};

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            ++size;
            ones += value[u];

            if (forced[u] != -1) {
                // flip = value[u] ^ forced[u] 才能满足固定值。
                int flip = value[u] ^ forced[u];
                valid[flip ^ 1] = false;
            }

            for (auto [v, w] : adj[u]) {
                int expected = value[u] ^ w;
                if (value[v] == -1) {
                    value[v] = expected;
                    q.push(v);
                } else if (value[v] != expected) {
                    cout << -1 << '\n';
                    return 0;
                }
            }
        }

        if (!valid[0] && !valid[1]) {
            cout << -1 << '\n';
            return 0;
        }

        int keep = valid[0] ? ones : size + 1;
        int flip = valid[1] ? size - ones : size + 1;
        answer += min(keep, flip);
    }

    cout << answer << '\n';
}
