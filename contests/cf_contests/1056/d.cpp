#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<int> candidates(n);
    iota(candidates.begin(), candidates.end(), 1);

    while (candidates.size() > 2) {
        int pivot = candidates[0];
        
        bool found_pair = false;
        for (size_t i = 1; i < candidates.size(); ++i) {
            cout << "? " << pivot << " " << candidates[i] << endl;
            int result;
            cin >> result;
            if (result == -1) { exit(0); } 
            if (result == 1) {
                found_pair = true;
                break;
            }
        }
        
        if (found_pair) {
            return;
        }

       
        candidates.erase(candidates.begin());
    }

    int final1 = candidates[0];
    int final2 = candidates[1];
    
    cout << "? " << final1 << " " << final2 << endl;
    int result;
    cin >> result;
    if (result == -1) { exit(0); }
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