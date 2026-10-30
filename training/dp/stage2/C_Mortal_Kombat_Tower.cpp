#include<bits/stdc++.h>
using namespace std;

const int INF = 1e9 + 5;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> A(n);
        vector<array<int,2> > dp(n+1, {INF, INF});
        dp[0][1] = 0;

        for(int i = 0; i < n; ++i) cin >> A[i];
        for(int i = 0; i < n; ++i){
            for(int who = 0; who <= 1; ++who){
                for(int fight = 1; fight <= min(2,n-i); ++fight){
                    int hards = A[i] + (fight == 2 ? A[i+1] : 0);
                    dp[i+fight][!who] = min(dp[i+fight][!who], dp[i][who] + who * hards);
                }
            }
        }

        cout << min(dp[n][0],dp[n][1]) << endl;

    }


}