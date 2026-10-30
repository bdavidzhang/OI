//CSES-Dice Combinatorics
#include<bits/stdc++.h>
using namespace std;

const int MOD = 1e9+7;

int main(){
    int n;
    cin >> n;

    vector<long long> dp(1e6+1);
    dp[0] = 1;
    dp[1] = 2;
    dp[2] = 4;
    dp[3] = 8;
    dp[4] = 16;
    dp[5] = 32;
    for(int i = 6; i < n; ++i){
        for(int j = 1; j <= 6; ++j){
            dp[i] += dp[i-j]; 
            dp[i] = dp[i] % MOD;
        } 
    }

    cout << dp[n-1] << endl; 

    return 0;
}
