#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<long long> v(n+2, 1e18);
    for(int i = 1; i <= n; ++i){
        cin >> v[i]; 
    }
    long long ans = 0;
    vector<int> L(n+2, 0), R(n+2, 0);
    for(int j = 1; j <= n; ++j){
        if(v[j] >= v[j-1]) L[j] = L[j-1];
        else L[j] = j; 
    }
    for(int j = n; j >= 1; --j){
        if(v[j] >= v[j+1]) R[j] = R[j+1];
        else R[j] = j; 
    }

    for(int i = 1; i <= n; ++i){
        if(v[i] >= v[i-1] && v[i] >= v[i+1]){
        long long lo = min(v[i] - v[L[i]], v[i] - v[R[i]]);
        ans = max(lo, ans);
        }
    }

    cout << ans << endl;

    return 0;
}
