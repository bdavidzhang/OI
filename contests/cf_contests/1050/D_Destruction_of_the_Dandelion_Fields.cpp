#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        long long ans = 0;
        vector<int> odds;
        for(int i = 0; i < n; ++i){
            int x;
            cin >> x;
            if(x % 2 == 1) odds.push_back(x);
            else ans += x;
        }
        sort(odds.begin(),odds.end());
        int sz = odds.size();
        if(sz == 0){
            cout << 0 << endl;
        }else{
            int med = sz/2;
            for(int i = med; i < sz; ++i){
                ans += odds[i];
            }
            cout << ans << endl;
        }
    }
    return 0;
}