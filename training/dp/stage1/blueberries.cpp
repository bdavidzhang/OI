//RPLB - Blueberries
#include<bits/stdc++.h>
using namespace std;


int main(){
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;

        vector<int> v(n);
        for(int &x : v) cin >> x;
        vector<vector<int>> dp(n,vector<int>(2));
        dp[n-1][0] = 0; 
        dp[n-1][1] = v[n-1];
        for(int i = n-2; i >= 0; --i){
            dp[i][0] = dp[i+1][1];
            dp[i][1] = max(dp[i+1][0] + v[i], dp[i+1][1]); 
        }
    cout << dp[0][1] << endl;
    }

    


    return 0;
}
