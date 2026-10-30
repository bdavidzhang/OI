#include<bits/stdc++.h>
using namespace std;

#define int long long
const int MOD = 1e9+7;
signed main(){
    int n;
    cin >> n;

    if(n <= 2){
        cout << n << endl;
        return 0;
    }

    vector<int> dp(n+2,0);
    vector<int> s(n+3,0);
    dp[n+1] = 1;
    s[n+1] = 1;

    for(int i = n; i >= 3; --i){
        int t1 = ((i-1) * dp[i+1]) % MOD;
        int t2 = ((i-2) * dp[i+2]) % MOD;

        dp[i] = (t1 + t2) % MOD;
    }

    int ans = (2 * dp[3]) % MOD;
    cout << ans << endl;

}