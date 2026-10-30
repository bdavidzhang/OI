#include<bits/stdc++.h>
using namespace std;


int main(){
    string s,t;
    cin >> s >> t;
    int n = int(s.size()), m = int(t.size());

    vector<vector<int> > dp(n+1, vector<int>(m+1,0));
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            dp[i+1][j+1] = s[i] == t[j] ? dp[i][j]+1 : max(dp[i+1][j],dp[i][j+1]);
        }
    }

    //now backtrack like knapsack

    string ans = "";
    int i = n, j = m;
    while(i > 0 && j > 0){
        if(s[i-1] == t[j-1]){
            ans += s[i-1];
            i--;j--;
        }else{
            if(dp[i-1][j] >= dp[i][j-1]) i--;
            else j--;
        }
    }
    reverse(ans.begin(),ans.end());

    cout << ans << endl;

    return 0;
}