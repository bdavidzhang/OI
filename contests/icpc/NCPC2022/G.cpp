#include<bits/stdc++.h>
using namespace std;

using ld = long double;

int main(){
    int n, k;
    cin >> n >> k;
    vector<ld> p(n);    
    for(int i =0;i < n; ++i)cin >> p[i];
    sort(p.begin(),p.end());
    reverse(p.begin(),p.end());
    vector<vector<ld>> dp(n,vector<ld>(k));
    dp[0][-1] = 1-p[0];
    dp[0][1] = p[0];
    for(int i = 1; i < n; ++i){
        for(int j = (i+1)*-1; j <= i+1; ++j){
            dp[i][j] = p[i]*dp[i-1][j-1] + (1-p[i])*dp[i-1][j+1]; 
        }     
    }

    ld ans = 0;
    for(int i = 0; i < n; ++i){
        ans = max(ans,dp[i][k]); 
    }

    cout << ans << endl;
    return 0;
}
