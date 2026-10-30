#include<bits/stdc++.h>
using namespace std;


int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<pair<int,int>> c(n);
    for(auto&x : c) cin >> x.first >> x.second;
    
    int ans = -1;
    // cout << ans << endl;
    for(int T = 0; T <= n; ++T){
        int cnt = 0;
        for(auto [a,b] : c){
            if(a <= T && T <= b) cnt++;
        }
        if(cnt == T) ans = max(ans, T);
    }

    cout << ans << endl;

    return 0;
}