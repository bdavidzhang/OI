#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

typedef long long ll;

// Helper to find the largest power of 2 less than or equal to x
ll get_max_pow2(ll x) {
    if (x <= 0) return 0;
    // Uses builtin clz (count leading zeros) for efficiency
    // __builtin_clzll returns undefined for 0, so we handled x<=0 above
    return 1ULL << (63 - __builtin_clzll(x));
}

void solve() {
    int n;
    cin >> n;
    if (n == -1) exit(0); // Should not happen based on problem statement

    // Initial query for the total sum of the array
    cout << "? 1 " << n << endl;
    ll total_sum;
    cin >> total_sum;
    if (total_sum == -1) exit(0);

    int l = 1, r = n;
    
    // Narrow down the range until we focus on a single element
    // strictly speaking, we just need to find the value, but finding the element is a sure way
    while (l < r) {
        int mid = l + (r - l) / 2;
        
        // Query the left half
        cout << "? " << l << " " << mid << endl;
        ll left_sum;
        cin >> left_sum;
        if (left_sum == -1) exit(0);
        
        // Derive right half sum
        ll right_sum = total_sum - left_sum;
        
        int left_len = mid - l + 1;
        int right_len = r - mid;
        
        // Calculate the theoretical maximum possible element in each half
        ll cap_left = left_sum - left_len + 1;
        ll cap_right = right_sum - right_len + 1;
        
        ll v_left = get_max_pow2(cap_left);
        ll v_right = get_max_pow2(cap_right);
        
        if (v_left > v_right) {
            // Left has potential for a strictly larger element
            r = mid;
            total_sum = left_sum;
        } else if (v_right > v_left) {
            // Right has potential for a strictly larger element
            l = mid + 1;
            total_sum = right_sum;
        } else {
            // Tie in potential capacity: use Density heuristic
            // Compare left_sum/left_len vs right_sum/right_len
            // Use __int128 to prevent overflow during cross-multiplication
            unsigned __int128 density_l = (unsigned __int128)left_sum * right_len;
            unsigned __int128 density_r = (unsigned __int128)right_sum * left_len;
            
            if (density_l >= density_r) {
                r = mid;
                total_sum = left_sum;
            } else {
                l = mid + 1;
                total_sum = right_sum;
            }
        }
    }
    
    // Output the found maximum value
    cout << "! " << total_sum << endl;
}

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    return 0;
}