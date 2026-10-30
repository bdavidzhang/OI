#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

// Struct to hold politician data
struct Politician {
    long long id;
    long long w, p, m;
    long long p_plus_m;
};

// Helper struct to manage two priority queues for finding top/bottom k elements
// It maintains two heaps to keep track of a target number of "selected" elements
// and efficiently calculates the sum of their primary and secondary values.
struct Selector {
    priority_queue<pair<long long, int>> small_half; // Max-heap
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> large_half; // Min-heap
    
    long long small_sum_p = 0, large_sum_p = 0;
    long long small_sum_m = 0, large_sum_m = 0;
    int target_size;
    const vector<Politician>& politicians;

    Selector(int k, const vector<Politician>& pols) : target_size(k), politicians(pols) {}

    void rebalance() {
        while (small_half.size() > target_size) {
            pair<long long, int> val = small_half.top();
            small_half.pop();
            large_half.push(val);
            small_sum_p -= politicians[val.second].p;
            small_sum_m -= politicians[val.second].m;
            large_sum_p += politicians[val.second].p;
            large_sum_m += politicians[val.second].m;
        }
        while (small_half.size() < target_size && !large_half.empty()) {
            pair<long long, int> val = large_half.top();
            large_half.pop();
            small_half.push(val);
            large_sum_p -= politicians[val.second].p;
            large_sum_m -= politicians[val.second].m;
            small_sum_p += politicians[val.second].p;
            small_sum_m += politicians[val.second].m;
        }
    }

    void add(long long value, int index) {
        if (!small_half.empty() && value < small_half.top().first) {
            small_half.push({value, index});
            small_sum_p += politicians[index].p;
            small_sum_m += politicians[index].m;
        } else {
            large_half.push({value, index});
            large_sum_p += politicians[index].p;
            large_sum_m += politicians[index].m;
        }
        rebalance();
    }
    
    void set_target_size(int k) {
        target_size = k;
        rebalance();
    }
};

bool check(int k, int n, const vector<Politician>& politicians) {
    if (k == 0) return true;
    if (n < 2 * k) return false;

    // Left selector: chooses k politicians to rob based on largest (p+m)
    // We store -(p+m) in a min-heap based selector to find the largest values.
    Selector left_selector(0, politicians);

    // Right selector: chooses (2k-i) politicians to help based on smallest p
    Selector right_selector(k, politicians);
    for (int i = k; i < n; ++i) {
        right_selector.add(politicians[i].p, i);
    }
    
    for (int i = k; i <= 2 * k && i < n; ++i) {
        // Move politician i from the right pool to the left pool
        // Since the right selector always rebalances, we don't need an explicit remove.
        // We add the new candidate to the left selector.
        left_selector.add(-(politicians[i - 1].p_plus_m), i - 1);
        left_selector.set_target_size(k);
        
        // Adjust the number of people to help from the right
        if (i > k) {
           right_selector.set_target_size(2 * k - i);
        }

        // Financial Check for pivot i
        long long gain = -left_selector.small_sum_m;
        long long cost = -left_selector.large_sum_p + right_selector.small_sum_p;

        if (gain >= cost) {
            return true;
        }
    }

    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<Politician> politicians(n);
    for (int i = 0; i < n; ++i) {
        politicians[i].id = i;
        cin >> politicians[i].w >> politicians[i].p >> politicians[i].m;
        politicians[i].p_plus_m = politicians[i].p + politicians[i].m;
    }

    sort(politicians.begin(), politicians.end(), [](const Politician& a, const Politician& b) {
        return a.w > b.w;
    });

    int low = 0, high = n / 2, ans = 0;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (check(mid, n, politicians)) {
            ans = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    cout << ans << endl;

    return 0;
}