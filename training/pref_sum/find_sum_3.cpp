#include<bits/stdc++.h>
using namespace std;

int main(){
    //simple case: here we want to find the sum of $3$ largst 
    //numbers in O(n) time. Sorting take O(nlogn).
    
    vector<int> a = {1,4,2,6,8};
    //the target value is 4 + 6 + 8 = 18. 

    int n = a.size();
    int k = 3;
    
    // vector<vector<int>> dp(n+1,vector<int>(3,-1e9));
    // for(int i = 0; i < n; ++i){
    //     dp[i+1][0] = max(dp[i][0], a[i]);
    //     dp[i+1][1] = max(dp[i][1], a[i] + dp[i][0]);
    //     dp[i+1][2] = max(dp[i][2], a[i] + dp[i][1]);
    // }

    // cout << dp[n][2] << endl;

    // in fact, we really need to keep track of only 3 numbers:
    //a_1, a_2, a_3, which represent dp[i][0], dp[i][1], dp[i][2].
    //Let's try this approach
    
    int a1 = -1e9, a2 = -1e9, a3 = -1e9;
    int a1_p = -1e9, a2_p = -1e9, a3_p = -1e9;

    for(int i = 0; i < n; ++i){
        a1 = max(a1_p,a[i]);
        a2 = max(a2_p,a[i]+a1_p);
        a3 = max(a3_p,a[i]+a2_p);
        a1_p = a1;
        a2_p = a2;
        a3_p = a3;
    }

    cout << a3 << endl;

    return 0;
}