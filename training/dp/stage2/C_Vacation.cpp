#include<bits/stdc++.h>
using namespace std;


const int INF = 1e9+5;

int main(){
    int n;
    cin >> n;

    vector<array<int, 3> > A(n);
    for(int i = 0; i < n; ++i){
        int a ,b , c;
        cin >> a >> b >> c;
        A[i] = {a,b,c}; 
    }

    vector<array<int, 3> > dp(n+10, {-INF,-INF,-INF});

    for(int j = 0; j < 3; ++j){
        dp[0][j] = A[0][j];
    }
    for(int i =0 ;i < n-1; ++i){
        for(int j = 0; j < 3; ++j){
            int cur = dp[i+1][j];
            if(j == 0){
                dp[i+1][j] = max(dp[i][1]+A[i+1][j],dp[i][2]+A[i+1][j]);
            }else if(j == 1){
                dp[i+1][j] = max(dp[i][0]+A[i+1][j],dp[i][2]+A[i+1][j]);
            }else{
                dp[i+1][j] = max(dp[i][0]+A[i+1][j],dp[i][1]+A[i+1][j]);
            }
            dp[i+1][j] = max(dp[i+1][j],cur);
        }
    }
    cout << max(dp[n-1][2],max(dp[n-1][0],dp[n-1][1])) << endl;

}