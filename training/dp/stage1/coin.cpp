#include<bits/stdc++.h>
using namespace std;


vector<int> f(100,100);
int v[5] = {1,3,6,10,15};


void solve() {
    int n;
    cin >> n;
    int ans = INT_MAX;
    if (n < 100) {
        cout << f[n] << endl;
        return;
    }
    // Try k, k-1, k-2 where k = n / 15
    int k = n / 15;
    for (int d = 0; d <= 2; ++d) {
        if (k - d >= 0) {
            int rem = n - (k - d) * 15;
            if (rem >= 0 && rem < 100) {
                ans = min(ans, (k - d) + f[rem]);
            }
        }
    }
    cout << ans << endl;
}



int main(){
    int t;
    cin >> t;
    f[1] = f[3] = f[6] = f[10] = f[15] = 1;
    for (int i = 1; i <= 99; ++i){
        if( i < 3){
            f[i] = min(f[i], f[i-1]+1);
        }else if( i < 6){
            f[i] = min(f[i],f[i-1]+1);
            f[i] = min(f[i],f[i-3]+1);
        }else if(i < 10){
            f[i] = min(f[i],f[i-1]+1);
            f[i] = min(f[i],f[i-3]+1);
            f[i] = min(f[i],f[i-6]+1);
        }else if(i < 15){
            f[i] = min(f[i],f[i-1]+1);
            f[i] = min(f[i],f[i-3]+1);
            f[i] = min(f[i],f[i-6]+1);
            f[i] = min(f[i],f[i-10]+1);
        }else{
            f[i] = min(f[i],f[i-1]+1);
            f[i] = min(f[i],f[i-3]+1);
            f[i] = min(f[i],f[i-6]+1);
            f[i] = min(f[i],f[i-10]+1);
            f[i] = min(f[i],f[i-15]+1);
        }
    }
    f[0] = 0;
    while(t--){
        solve();
    }


}
