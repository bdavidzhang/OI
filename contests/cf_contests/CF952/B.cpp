#include<bits/stdc++.h>
using namespace std;

using ll = long long;


void solve(){
    int n;
    cin >> n;
    ll sum = 0;
    ll maxi = -1, indx = 1;
    for(int x = 2; x <= n; ++x){
        sum = 0;
        for(int k = 1; k <= n/x; ++k){
            sum += k*x; 
        } 
        if (sum > maxi){
            maxi = sum;
            indx = x; 
        }
    }

    cout << indx << endl;

}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--){
        solve(); 
    }


    return 0;
}
