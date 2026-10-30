#include<bits/stdc++.h>
using namespace std;

bool check_consistency(long long a0, const vector<char>& c) {
    long long n = c.size();
    if (n == 0) return a0 == 0;
    
    long long num_L = 0;
    for (char choice : c) {
        if (choice == 'L') {
            num_L++;
        }
    }
    
    long long a0_calculated = num_L + (c[0] == 'R');
    return a0 == a0_calculated;
}

void solve() {
    int n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    
    if (n == 1) {
        cout << 2 << "\n";
        return;
    }

    vector<char> choices(n, '?');
    bool is_any_fixed = false;

    for (int i = 0; i < n - 1; ++i) {
        long long diff = a[i + 1] - a[i];
        if (abs(diff) > 1) {
            cout << 0 << "\n";
            return;
        }
        if (diff == 1) {
            if ((choices[i] == 'L') || (choices[i + 1] == 'L')) { cout << 0 << "\n"; return; }
            choices[i] = 'R';
            choices[i + 1] = 'R';
            is_any_fixed = true;
        } else if (diff == -1) {
            if ((choices[i] == 'R') || (choices[i + 1] == 'R')) { cout << 0 << "\n"; return; }
            choices[i] = 'L';
            choices[i + 1] = 'L';
            is_any_fixed = true;
        }
    }

    if (!is_any_fixed) {
        int valid_count = 0;
        
        vector<char> c1(n);
        for(int i = 0; i < n; ++i) c1[i] = (i % 2 == 0) ? 'L' : 'R';
        if (check_consistency(a[0], c1)) valid_count++;

        vector<char> c2(n);
        for(int i = 0; i < n; ++i) c2[i] = (i % 2 == 0) ? 'R' : 'L';
        if (check_consistency(a[0], c2)) valid_count++;
        
        cout << valid_count << "\n";
    } else {
        bool changed = true;
        while(changed) {
            changed = false;
            for (int i = 0; i < n - 1; ++i) {
                if (a[i+1] - a[i] == 0) { 
                    if (choices[i] != '?' && choices[i+1] == '?') {
                        choices[i+1] = (choices[i] == 'L' ? 'R' : 'L');
                        changed = true;
                    }
                }
            }
            for (int i = n - 2; i >= 0; --i) {
                 if (a[i+1] - a[i] == 0) { 
                    if (choices[i+1] != '?' && choices[i] == '?') {
                        choices[i] = (choices[i+1] == 'L' ? 'R' : 'L');
                        changed = true;
                    }
                }
            }
        }
        
        bool possible = true;
        for(int i = 0; i < n; ++i) if(choices[i] == '?') { possible = false; break; }
        if (!possible) {
            cout << 0 << "\n";
            return;
        }

        for(int i = 0; i < n - 1; ++i) {
            long long diff = a[i+1] - a[i];
            char c_i = choices[i];
            char c_i_plus_1 = choices[i+1];
            
            if (diff == 1 && (c_i != 'R' || c_i_plus_1 != 'R')) possible = false;
            if (diff == -1 && (c_i != 'L' || c_i_plus_1 != 'L')) possible = false;
            if (diff == 0 && c_i == c_i_plus_1) possible = false;
            if (!possible) break;
        }

        if(possible && check_consistency(a[0], choices)) {
            cout << 1 << "\n";
        } else {
            cout << 0 << "\n";
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}