//boss fight
#include<bits/stdc++.h>
using namespace std;


bool check(long long h, vector<int> &a, vector<int> &c, long long n, long long k){
    long long total = 0;
    for(int i = 0; i < n; ++i){
        long long tries = (k-1) / c[i] + 1;
        total += tries * a[i];
    } 
    return total >= h;
}


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
        long long high = 4*1e10;
        long long ans = low;

        while(low <= high){
            long long mid = (high+low) / 2;
            
            if(check(h,a,c,n,mid)){
                high = mid-1;
            }else{
                low = mid+1;
            }
            ans = mid;
        }

        cout << ans << endl;        

    }


    return 0;
}