//max value yielding path in a grid
#include<bits/stdc++.h>
using namespace std;

int main(){
    int m,n;
    cin >> m >> n;
    //m rows, n cols
    vector<vector<int>> val(m,vector<int>(n));
    for(int i = 0; i < m; ++i){
        for(int j = 0; j < n; ++j){
            cin >> val[i][j];
        }
    }

    vector<vector<int>> dp(m,vector<int>(n));
    dp[0][0] = val[0][0];
    for(int i = 1; i < m; ++i) dp[i][0] = dp[i-1][0] + val[i][0];
    for(int j = 1; j < n; ++j) dp[0][j] = dp[0][j-1] + val[0][j];
   
    for(int i = 1; i < m; ++i){
        for(int j = 1; j < n; ++j){
            dp[i][j] = max(dp[i-1][j],dp[i][j-1]) + val[i][j]; 
        } 
    }
    
    cout << dp[m-1][n-1] << endl;
    return 0;
}

