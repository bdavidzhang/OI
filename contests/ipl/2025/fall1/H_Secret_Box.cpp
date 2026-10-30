#include<bits/stdc++.h>
using namespace std;

#define int long long

signed main(){
    int t;
    cin >> t;
    while(t--){
        int x,y,z,k;
        cin >> x >> y >> z >> k;

        long long ans = 0;
        for(int a = 1; a <= x; ++a){
            for(int b = 1; b <= y; ++b){
                if(k % (a*b) != 0) continue;
                int c = k / (a*b);
                if(c > z) continue;
                long long res = 1LL * (x+1-a) * (y+1-b) *(z+1-c);
                ans = max(ans, res);
            }
        }

        cout << ans << endl;
        
    }


    return 0;

}