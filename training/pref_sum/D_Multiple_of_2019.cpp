#include<bits/stdc++.h>
using namespace std;


const int MOD = 2019;

int pow(int a, int b){
    int res = 1;
    while(b){
        if(b & 1) res = res * a % MOD;
        a = (a % MOD) * (a % MOD) % MOD;
        b >>= 1;
    }
    return res % MOD;
}


int main(){
    string s;
    cin >> s;
    int n = s.size();
    vector<int> dp(n+1,0);
    reverse(s.begin(),s.end());
    long long ans = 0;
    map<int,int> d;
    d[0] = 1;
    for(int i = 1; i <= n; ++i){
        long long term = (long long)(s[i-1]-'0') * pow(10, i-1);
        dp[i] = (dp[i-1] + term) % MOD;
        d[dp[i]]++;
        ans += d[dp[i]] - 1; 
    }


    // for(auto &x : dp){
    //     cout << x << " ";
    // }
    // cout << endl;
    
    cout << ans << endl;


    return 0;    
}