#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int lo1 = 1;
        int hi2 = 1000;
        int hi1 = lo1 + (hi2-lo1)/2;
        int lo2 = hi1+1;
        int ans = lo1;
        while(lo1 <= hi1 || lo2 <= hi2){
            int mid1 = lo1 + (hi1-lo1)/2;
            int mid2 = lo2 + (hi2-lo2)/2;
            cout << "?" << " " << mid1 << " " << mid2 << endl;
            cout.flush();
            int res;
            cin >> res;
            if(res == mid1 * mid2){
                lo1 = mid2+1;
                ans = mid2;
            }else if(res == mid1* (mid2+1)){
                lo1 = mid1+1;
                hi2 = mid2-1;
            }else{
                hi2 = mid1-1;
            }
            int hi1 = lo1 + (hi2-lo1)/2;
            int lo2 = hi1+1; 
        }
        cout << "!" << " " << ans+1 << endl;
        
    }
    return 0;
}