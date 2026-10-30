#include<bits/stdc++.h>
using namespace std;

const int INF = 1e9+5;
const int maxn = 5005;
int dp[maxn][maxn];
string A,B;

int solve(int i, int j){//i,j length of prefix
    if(dp[i][j] != INF) return dp[i][j];
    if(i == 0) return dp[i][j] = j;
    if(j == 0) return dp[i][j] = i;

    int ans1 = solve(i,j-1)+1;
    int ans2 = solve(i-1,j)+1;
    int ans3 = solve(i-1,j-1)+(A[i-1] != B[j-1]);
    
    
    return dp[i][j] = min({ans1,ans2,ans3});
}

int main(){
    cin >> A >> B;
    int m = A.size(), n = B.size();

    for(int i = 0; i <= m; ++i)
        for(int j = 0; j <= n; ++j) 
            dp[i][j] = INF;

    int ans = solve(m,n);

    cout << ans << endl;
}