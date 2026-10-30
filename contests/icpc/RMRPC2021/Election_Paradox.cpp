#include<bits/stdc++.h>
using namespace std;
using ll = long long;


int main(){
    int n;
    cin >> n;
    ll ans = 0;
    vector<int> v(n);
    for(int i = 0; i < n; ++i) cin >> v[i];
    sort(v.begin(),v.end());

    for(int i = 0; i < n/2; ++i){
        ans += v[n-1-i];
    }
    for(int i = n/2; i < n; ++i){
        ans += v[n-1-i]/2;
    }

    cout << ans << endl;

    return 0;
}