#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    int t;
    cin >> t;
    while(t--){
        int n, P, l, t;
        cin >> n >> P >> l >> t;
        int tmax = (n-1)/7 + 1;
        int ans = 1;
        int lo = 1;
        int hi = n;
        // cout << "tmax: " << tmax << endl;
        while(lo <= hi){
            int mid = lo +(hi-lo)/2;
            if(mid*l + min(2*mid,tmax)*t >= P){
                ans = mid;
                hi = mid-1;
            }else{
                lo = mid+1;
            }
        }
        cout << n-ans << endl;

    }
    return 0;
}