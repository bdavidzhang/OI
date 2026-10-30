#include<bits/stdc++.h>
using namespace std;

int main(){

    int n;
    cin >>n;
    vector<int> h(n);
    for(int&x : h) cin >> x;

    vector<long long> dp(n);
    dp[n-1] = 0;
    dp[n-2] = abs(h[n-2]-h[n-1]);
    for(int i = n-3;i >= 0; --i){
        dp[i] = min(dp[i+1]+abs(h[i]-h[i+1]),dp[i+2]+abs(h[i]-h[i+2])); 
    }

    cout << dp[0] << endl;
}
