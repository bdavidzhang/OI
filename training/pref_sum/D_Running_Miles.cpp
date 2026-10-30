#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        
        vector<int> b(n);
        for(auto& x: b) cin >> x;
        
        vector<int> prev_mx(n), suff_mx(n);
        for(int i = 0; i < n; ++i){
            prev_mx[i] = b[i] + i;
            suff_mx[i] = b[i] - i;
        }
        for(int i = 1; i < n; ++i){
            prev_mx[i] = max(prev_mx[i-1],b[i]+i);
        }
        for(int i = n-2; i >= 0; --i){
            suff_mx[i] = max(suff_mx[i+1],b[i]-i);
        }

        int ans = -10;
        for(int m = 1; m <= n-2; ++m){
            ans = max(ans, prev_mx[m-1]+b[m]+suff_mx[m+1]);
        }
        cout << ans << endl;
    }
    return 0;
}