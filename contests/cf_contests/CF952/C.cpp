#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<long long>;

void solve(){
    int n;
    cin >> n;

    vi v(n+1);
    vll pref(n+1); 
    ll cnt = 0;

    ll max = -1;

    for(int i = 1; i <= n; ++i){
        cin >> v[i];
        if(v[i] > max) max = v[i]; 
        pref[i] = pref[i-1] +v[i];
        if(pref[i] == 2*max) cnt++;
    }

    
    cout << cnt << endl;

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
