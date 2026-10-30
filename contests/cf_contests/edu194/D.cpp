#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        if (s[0] == '0') {
            cout << -1 << '\n';
            continue;
        }

        bool flip = false;
        bool three = false;
        bool two = false;
        bool no = false;
        for (int i = 1; i < n; ++i) {
            if (s[i] == '0' && s[i - 1] == '0') {
                no = true;
                break;
            }
            if ((s[i] == '+' && s[i - 1] == '-') ||
                (s[i] == '-' && s[i - 1] == '+')) {
                flip = true;
            }
            if (i >= 3 && s[i] == s[i - 3] &&
                s[i - 1] == s[i - 2] &&
                s[i] != s[i - 1] && s[i] != '0') {
                three = true;
            }
        }

        for (int left = 0; left < n;) {
            if (s[left] == '0') {
                ++left;
                continue;
            }
            int right = left;
            while (right < n && s[right] == s[left]) {
                ++right;
            }
            if (right < n && s[right] == '0' && (right - left) % 2 == 0) {
                two = true;
            }
            left = right;
        }

        if (no) {
            cout << -1 << '\n';
        } else if (three) {
            cout << 3 << '\n';
        } else if (flip || two) {
            cout << 2 << '\n';
        } else {
            cout << 1 << '\n';
        }



    }
    return 0;
}
