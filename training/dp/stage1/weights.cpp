//Knapsack problem weights
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,t;
    cin >> n >> t;
    vector<int> v(n+1);
    for(int i = 1 ;i <=n; ++i){
        cin >> v[n]; 
    }
        
    vector<vector<bool>> dp(t+10,vector<bool>(n+10));

    dp[0][0] = true;
    for(int i = 1; i <= n; ++i){
        dp[v[i]][i] = true; 
    } 
    for(int i = 1; i <= t; ++i){
        for(int j = 1; j <= n; ++j){
            dp[i][j] = dp[i][j-1] || dp[i-v[j]][j-1]; 
        }
    }

    for(int i = 0; i <= t; ++i){
        bool flag = false;
        for(int j = 1; j <= n; ++j){
            if(dp[i][j]) flag = true ;
        } 
        if(flag) cout << 1 << " ";
    }
    cout << endl;

    return 0;
}
