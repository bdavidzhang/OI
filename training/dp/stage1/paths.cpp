//paths in a grid
#include<bits/stdc++.h>
using namespace std;

const int MOD = 1e9+7;

int main(){
    int m,n;
    cin >> n;
    m = n;
    //m rows, n cols
    vector<vector<bool>> val(m,vector<bool>(n));
    for(int i = 0; i < m; ++i){
        for(int j = 0; j < n; ++j){
            char c; 
            cin >> c;
            if(c == '.')val[i][j] = true;
            else val[i][j] = false;
            
        }
    }

    vector<vector<int>> dp(m,vector<int>(n));
    if(val[0][0])dp[0][0] = 1;
    for(int i = 1; i < m; ++i) dp[i][0] = (val[i][0] && dp[i-1][0]) ? 1 : 0;
    for(int j = 1; j < n; ++j) dp[0][j] = (val[0][j] && dp[0][j-1]) ? 1 : 0;

    for(int i = 1; i < m; ++i){
        for(int j = 1; j < n; ++j){
            if(val[i][j]){
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
                dp[i][j] = dp[i][j] % MOD;
            }
            else dp[i][j] = 0;
        } 
    }

    cout << dp[m-1][n-1] << endl;    

    return 0;
}

