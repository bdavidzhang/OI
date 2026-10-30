#include<bits/stdc++.h>
using namespace std;

int n,k;

void solve(){
    cin >> n>> k;
    if(k >= n-1) cout << 1 << endl;
    else cout << n << endl;
}


int main(){
    int tt;
    cin >> tt;
    while(tt--){
        solve();
    }

    return 0;

}