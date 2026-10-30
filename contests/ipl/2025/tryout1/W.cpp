#include<bits/stdc++.h>
using namespace std;


int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    string s;
    cin >> s;

    vector<int> dp(n+1,-1), par(n+1,-1);
    vector<int> max_dp_val(26,-1), max_dp_idx(26,-1);

    dp[0] = 0;
    max_dp_val[s[0]-'a'] = 0;
    max_dp_idx[s[0]-'a'] = 0;

    for(int i = 2; i <= n; ++i){
        int prev = i-2;
        char prev_char = s[prev];

        if (dp[prev] != -1 && dp[prev] > max_dp_val[prev_char - 'a']){
            max_dp_val[prev_char - 'a'] = dp[prev];
            max_dp_idx[prev_char - 'a'] = prev;
        }

        char c = s[i-1];
        int j = max_dp_idx[c-'a'];
        if( j != -1){
            dp[i] = max_dp_val[c-'a'] + 1;
            par[i] = j;
        }
    }

    if(dp[n] == -1){
        cout << -1 << endl;
        return 0;
    }
    
    cout << dp[n] << endl;

    vector<int> ans;
    for(int cur = n; cur > 0; cur = par[cur]){
        ans.push_back(cur-par[cur]);
    }
    reverse(ans.begin(),ans.end());
    for(int i = 0; i < int(ans.size()) -1;++i){
        cout << ans[i] << " ";
    }
    cout << ans[int(ans.size())-1] << endl;


    return 0;
}