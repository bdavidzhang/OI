#include<bits/stdc++.h>
using namespace std;
#define int long long


signed main(){
    int n;
    cin >> n;
    vector<int> x(n),y(n);
    for(int i = 0; i < n; ++i){
        cin >> x[i] >> y[i];
    }

    if(n % 2 == 1) cout << "NO" << endl;
    else{
        int k = n/2;
        int midx = (x[0] + x[k]);
        int midy = (y[0] + y[k]);
        bool flag = true;
        for(int i = 1; i < k; ++i){
            int cur_midx = (x[i] + x[i+k]);
            int cur_midy = (y[i] + y[i+k]);
            if(cur_midx != midx || cur_midy != midy){
                flag = false;
            }
        }

        if(flag){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
    }
    
    return 0;
}