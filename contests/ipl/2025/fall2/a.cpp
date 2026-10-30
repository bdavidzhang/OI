#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    int t;
    cin >> t;
    while(t--){
        int l, r; 
        cin >> l >> r;
        
        int lo = 1;
        int hi = 2000000; // Better upper bound based on constraint
        int ans = 0;
        
        while(lo <= hi){
            int mid = lo + (hi - lo) / 2; // Proper midpoint calculation
            
            if(mid * (mid + 1) / 2 <= r-l){
                ans = mid;      // Update answer when condition is satisfied
                lo = mid + 1;   // Need larger values
            } else {
                hi = mid - 1;   // Look for smaller values
            }
        }
        
        cout << ans + 1<< endl;
    }
    return 0;
}