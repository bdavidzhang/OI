#include <iostream>
#include <string>
#include <vector>
#include <map>

void solve() {
    int n;
    std::cin >> n;
    std::string s;
    std::cin >> s;

    if (n <= 2) {
        std::cout << "no\n";
        return;
    }

    std::map<char, int> freq;
    bool found_duplicate = false;

    // Include frequencies for s[0] and s[n-1]
    freq[s[0]]++;
    freq[s[n-1]]++;

    for (int i = 1; i < n - 1; ++i) {
        freq[s[i]]++;
        if (freq[s[i]] >= 2) {
            found_duplicate = true;
            break;
        }
    }

    if (found_duplicate) {
        std::cout << "yes\n";
    } else {
        std::cout << "no\n";
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}