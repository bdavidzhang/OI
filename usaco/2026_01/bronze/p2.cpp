#include <bits/stdc++.h>

using namespace std;

void solve() {
    int FjString;
    if (!(cin >> FjString)) return;
    string s;
    cin >> s;

    if (FjString % 2 != 0) {
        cout << -1 << "\n";
        return;
    }

    int n_half = FjString / 2;
    vector<int> block_types(FjString);
    for (int i = 0; i < FjString; ++i) {
        char c = s[3 * i];
        if (c == 'C') block_types[i] = 0;
        else if (c == 'O') block_types[i] = 1;
        else block_types[i] = 2;
    }

    bool possible_1 = true;
    for (int i = 0; i < n_half; ++i) {
        if (block_types[i] != block_types[i + n_half]) {
            possible_1 = false;
            break;
        }
    }

    if (possible_1) {
        cout << 1 << "\n";
        for (int i = 0; i < 3 * FjString; ++i) {
            cout << 1 << (i == 3 * FjString - 1 ? "" : " ");
        }
        cout << "\n";
    } else {
        cout << 2 << "\n";
        vector<int> ans(3 * FjString);
        for (int i = 0; i < n_half; ++i) {
            int l = block_types[i];
            int r = block_types[i + n_half];
            int diff = (r - l + 3) % 3;
            int base_l = 3 * i;
            int base_r = 3 * (i + n_half);

            if (diff == 0) {
                for (int k = 0; k < 3; ++k) ans[base_l + k] = 1;
                for (int k = 0; k < 3; ++k) ans[base_r + k] = 1;
            } else if (diff == 1) {
                ans[base_l] = 2; ans[base_l+1] = 1; ans[base_l+2] = 1;
                ans[base_r] = 1; ans[base_r+1] = 1; ans[base_r+2] = 2;
            } else {
                ans[base_l] = 1; ans[base_l+1] = 1; ans[base_l+2] = 2;
                ans[base_r] = 2; ans[base_r+1] = 1; ans[base_r+2] = 1;
            }
        }
        for (int i = 0; i < 3 * FjString; ++i) {
            cout << ans[i] << (i == 3 * FjString - 1 ? "" : " ");
        }
        cout << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t, k;
    if (cin >> t >> k) {
        while (t--) {
            solve();
        }
    }
    return 0;
}