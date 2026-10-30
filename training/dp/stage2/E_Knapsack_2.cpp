#include<bits/stdc++.h>
using namespace std;


const int INF = 1e9+5;

int main(){
    int n, W;
    cin >> n >> W;

    vector<int> v(n),w(n);    

    int totv = 0;
    for(int i = 0; i < n; ++i){
        cin >> w[i] >> v[i];
        totv += v[i];
    }

    //value based dp, want to find min weight for each value v;
    vector<int> dp(totv+1,INF);
    dp[0] = 0;

    for(int i = 0; i < n; ++i){
        for(int val = totv - v[i]; val >= 0; --val){
            if(dp[val] != INF){
                dp[val+v[i]] = min(dp[val]+w[i],dp[val+v[i]]);
            }
        }
    }

    int ans = 0;
    for(int val = 0; val <= totv; ++val){
        if(dp[val] <= W){
            ans = val;
        }
    }

    cout << ans << endl;


    return 0;
}