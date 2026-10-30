//boss fight
#include<bits/stdc++.h>
using namespace std;



int main(){
    
    int t;
    cin >> t;
    while(t--){
        long long h,n;
        cin >> h >> n;
        vector<int> a(n), c(n); 
        
        for(int i=0; i<n; i++) cin >> a[i];
        for(int i=0; i<n; i++) cin >> c[i];
        
        
        
        
        long long low = 1;
        long long high = 4LL * 10000000000LL + 4LL;
        long long ans = high;
        
        
        auto check = [&](long long k) -> bool{
            long long total = 0;
            for(int i = 0; i < n; ++i){
               long long tries = (k-1) / c[i] + 1;
               total += tries * a[i]; 
               if (total >= h) return true;
            }
            return false;
        };


        while(low <= high){
            long long mid = (high+low) / 2;
            
            if(mid == 0){
                low = 1;
                continue;
            }
            if(check(mid)){
                high = mid-1;
                ans = mid;
            }else{
                low = mid+1;
            }
        }

        cout << ans << endl;        

    }


    return 0;
}