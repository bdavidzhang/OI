//CSES-coins 2 
//counting from sorted to unsorted - refer to DP textbook
#include<bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int main(){
    int n, k;
    cin >> n >> k; 
    
    vector<int> coins(n);
    for(int i = 0; i < n; ++i) cin >> coins[i];
    sort(coins.begin(),coins.end()); 
     
    vector<long long> dp(1e6+1);
    for(int i = 0; i <= coins[n-1]; ++i){
        if( i < coins[0]) dp[i] = 0;
        else{
            if(binary_search(coins.begin(),coins.end(),i)){
                dp[i] = 1; 
            }
            for(int j = 0; j < n; ++j){
                if(i - coins[j] >= 0) dp[i] += dp[i-coins[j]]; 
                dp[i] = dp[i] % MOD;
            }
        } 
    }
    for(int i = coins[n-1]+1; i <= k; ++i){
        for(int j = 0; j < n; ++j){
            dp[i] += dp[i-coins[j]]; 
            dp [i] = dp[i] % MOD;
        } 
    }
    cout << dp[k] << endl;

    return 0;
}

