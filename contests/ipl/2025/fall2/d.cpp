#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int lo = 1;
        int hi = 1000;
        int ans = lo;
        while(lo <= hi){
            int mid = lo + (hi-lo)/2;
            cout << "?" << " " << 1 << " " << mid << endl;
            cout.flush();
            int res;
            cin >> res;
            if(res <= mid){
                lo = mid+1;
                ans = mid;
            }else{
                hi = mid-1;
            }
        }
        cout << "!" << " " << ans+1 << endl;
        
    }
    return 0;
}