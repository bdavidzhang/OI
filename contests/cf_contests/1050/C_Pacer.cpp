#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n,m;
        cin >> n >> m;
        int pos = 0;
        int time = 0; 
        int ans = 0;
        while(n--){
            int t, p;
            cin >> t >> p;
            if(pos == p) ans += (t - time) / 2 * 2;
            else ans += (t - time - 1) / 2 * 2 + 1;
            time = t;
            pos = p;
            // cout << ans << endl;
        }
        ans += m-time;
        cout << ans << endl;
       

    }
    return 0;
}