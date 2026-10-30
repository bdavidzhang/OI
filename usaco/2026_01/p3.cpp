#include<bits/stdc++.h>


using namespace std;

void solve() {
    int FjString, K;
    if (!(cin >> FjString >> K)) return;
    
    string r;
    cin >> r;

    vector<int> b(FjString, 0);
    vector<int> chain_len(K, 0);
    vector<int> chain_cnt0(K, 0);

    for (int i = 0; i < K; ++i) {
        int curr = i;
        int val = 0;
        while (curr < FjString) {
            chain_len[i]++;
            if (val == 1) chain_cnt0[i]++;
            
            if (curr + K < FjString) {
                int r_curr = r[curr] - '0';
                int r_next = r[curr + 1] - '0';
                if (r_curr != r_next) {
                    val = 1 - val;
                }
            }
            curr += K;
        }
    }

    int base_ones = 0;
    vector<int> diffs(K);
    for (int i = 0; i < K; ++i) {
        base_ones += chain_cnt0[i];
        diffs[i] = chain_len[i] - 2 * chain_cnt0[i];
    }

    sort(diffs.begin(), diffs.end());

    int target_parity = r[0] - '0';

    long long current_sum = base_ones;
    int flip_count = 0;
    
    for (int d : diffs) {
        if (d < 0) {
            current_sum += d;
            flip_count++;
        }
    }

    if (flip_count % 2 != target_parity) {
        long long cost_remove = 1e18, cost_add = 1e18;
        
        for (int i = 0; i < K; ++i) {
            if (diffs[i] < 0) {
                cost_remove = -diffs[i]; 
            } else {
                cost_add = diffs[i];
                break;
            }
        }
        
        if (cost_remove < 1e17 && cost_add < 1e17) {
            if (cost_remove < cost_add) current_sum += cost_remove;
            else current_sum += cost_add;
        } else if (cost_remove < 1e17) {
            current_sum += cost_remove;
        } else {
            current_sum += cost_add;
        }
    }
    long long min_ans = current_sum;

    current_sum = base_ones;
    flip_count = 0;
    for (int d : diffs) {
        if (d > 0) {
            current_sum += d;
            flip_count++;
        }
    }

    if (flip_count % 2 != target_parity) {
        long long cost_remove = 1e18, cost_add = 1e18;
        
        for (int i = K - 1; i >= 0; --i) {
            if (diffs[i] > 0) {
                cost_remove = diffs[i]; 
            } else {
                cost_add = -diffs[i]; 
                break;
            }
        }

        if (cost_remove < 1e17 && cost_add < 1e17) {
            if (cost_remove < cost_add) current_sum -= cost_remove;
            else current_sum -= cost_add;
        } else if (cost_remove < 1e17) {
            current_sum -= cost_remove;
        } else {
            current_sum -= cost_add;
        }
    }
    long long max_ans = current_sum;

    cout << min_ans << " " << max_ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    if (cin >> T) {
        while (T--) {
            solve();
        }
    }
    return 0;
}