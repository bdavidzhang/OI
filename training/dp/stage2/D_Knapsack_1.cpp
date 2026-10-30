#include<bits/stdc++.h>
using namespace std;

const int maxn = 105;
const int maxw = 1e5+10;
// const int INF = 1e9+10;
long long dp[maxn][maxw];
int wv[maxn][2];


int main(){
    int n, W;
    cin >> n >> W;
    for(int i = 1;i <= n; ++i){
        int w,v;
        cin >> w >> v;
        wv[i][0] = w;
        wv[i][1] = v;
        for(int j = 0; j < w; ++j){
            dp[i][j] = dp[i-1][j];
        }
        for(int j = w; j <= W; ++j){
            dp[i][j] = max(dp[i-1][j],dp[i-1][j-w]+v);
        }
    }

    // for(int i = 0; i <= n; ++i){
    //     for(int j = 0; j <= W; ++j){
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    cout << dp[n][W] << endl;



    return 0;
}
