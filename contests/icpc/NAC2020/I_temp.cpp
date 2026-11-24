#include <bits/stdc++.h>
using namespace std;

constexpr int MOD = 998244353;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    int d;
    cin >> s >> d;
    int n = s.size();

    vector<int> pow3(n + 1, 1);
    for (int j = 1; j <= n; ++j) {
        pow3[j] = 3 * pow3[j - 1];
    }
    int states = pow3[n];

    // s 中出现的字母单独处理，其余字母共用一个转移。
    vector<pair<char, int>> letters;
    int other = 26;
    for (char c = 'A'; c <= 'Z'; ++c) {
        if (s.find(c) != string::npos) {
            letters.emplace_back(c, 1);
            --other;
        }
    }
    if (other > 0) {
        letters.emplace_back('#', other);
    }
    int kinds = letters.size();

    vector<vector<int>> go(states, vector<int>(kinds));
    vector<int> offset(states);
    vector<int> row(n + 1), next_row(n + 1);

    for (int st = 0; st < states; ++st) {
        // 解码每一位。三进制数字 0、1、2 对应差值 -1、0、1。
        // row[j] = dist(t, s 的长度 j 前缀) - |t|。
        row[0] = 0;
        int code = st;
        for (int j = 1; j <= n; ++j) {
            row[j] = row[j - 1] + code % 3 - 1;
            code /= 3;
        }
        offset[st] = row[n];

        for (int k = 0; k < kinds; ++k) {
            char c = letters[k].first;

            // 新旧两行都先减去旧长度 |t|，所以新行首项是 1。
            next_row[0] = 1;
            int to = 0;
            for (int j = 1; j <= n; ++j) {
                next_row[j] = min({
                    row[j] + 1,
                    next_row[j - 1] + 1,
                    row[j - 1] + (s[j - 1] != c)
                });

                int digit = next_row[j] - next_row[j - 1] + 1;
                to += digit * pow3[j - 1];
            }
            go[st][k] = to;
        }
    }

    // 空串的编辑距离行是 [0, 1, ..., n]，所以每一位都是 2。
    vector<int> dp(states), ndp(states);
    dp[states - 1] = 1;

    int ans = 0;
    for (int len = 0; len <= n + d; ++len) {
        for (int st = 0; st < states; ++st) {
            if (len + offset[st] == d) {
                ans += dp[st];
                if (ans >= MOD) ans -= MOD;
            }
        }

        if (len == n + d) break;

        fill(ndp.begin(), ndp.end(), 0);
        for (int st = 0; st < states; ++st) {
            if (dp[st] == 0) continue;

            for (int k = 0; k < kinds; ++k) {
                int to = go[st][k];
                int multiplicity = letters[k].second;
                int add = 1LL * dp[st] * multiplicity % MOD;
                ndp[to] += add;
                if (ndp[to] >= MOD) ndp[to] -= MOD;
            }
        }
        dp.swap(ndp);
    }

    cout << ans << '\n';
}
