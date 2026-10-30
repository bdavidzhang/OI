#include<bits/stdc++.h>

using namespace std;

const int INF = 1e9 + 10;

int main(){
    int n;
    cin >> n;
    
    vector<int> H(n+10);
    for(int i = 0; i < n; ++i) cin >> H[i];

    vector<int> dp(n+10,INF);
    dp[0] = 0;
    for(int i = 0; i < n-1; ++i){
        for(int j = 1; j <= min(n-i,2); ++j){
            dp[i+j] = min(dp[i+j],dp[i]+abs(H[i]-H[i+j]));
        }
    }

    // for(int i =0 ;i < n; ++i) cout << dp[i] << " ";
    // cout << endl;

    cout << dp[n-1] << endl;


    return 0;
}