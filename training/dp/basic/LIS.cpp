#include<bits/stdc++.h>
using namespace std;

int main(){

    int n;
    cin >> n;
    vector<int> A(n+1,0);
    for(int i = 1; i <= n; ++i) cin >> A[i];
    vector<vector<int>> dp(n+1,vector<int>(n+1,0));
    for(int i = 1; i <= n; ++i){
        for(int j = i-1; j >= 0; --j){
            if(A[i] > A[j]) dp[i][j] = max(dp[i][j],dp[j][j]+1);
        }
    }

    for(int i = 0; i <= n; ++i){
        for(int j = 0; j <= n; ++j){
            cout << dp[i][j];
        }
        cout << endl;
    }

    
    

    return 0;
}