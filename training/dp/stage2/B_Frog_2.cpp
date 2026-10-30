#include<bits/stdc++.h>

using namespace std;

const int INF = 1e9 + 10;

int main(){
    int N;
    cin >> N;
    int K; 
    cin >> K;
    
    vector<int> H(N+10);
    for(int i = 0; i < N; ++i) cin >> H[i];

    vector<int> dp(N+10,INF);
    dp[0] = 0;
    for(int i = 0; i < N-1; ++i){
        for(int j = 1; j <= min(N-i,K); ++j){
            dp[i+j] = min(dp[i+j],dp[i]+abs(H[i]-H[i+j]));
        }
    }

    // for(int i =0 ;i < n; ++i) cout << dp[i] << " ";
    // cout << endl;

    cout << dp[N-1] << endl;


    return 0;
}