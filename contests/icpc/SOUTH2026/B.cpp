#include<bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    int n = 3;
    vector<int> v(n), d(n);
    for(int i = 0; i < n; ++i){
        cin >> v[i]; 
    }    
    sort(all(v));
    for(int i = 0; i < n; ++i){
        d[i] = min(abs(v[(i+1)%n] - v[i]),N-abs(v[(i+1)%n] - v[i]));
    }


    sort(all(d));
    d.erase(unique(all(d)),d.end());
    int k = d.size();
    
    int ans = LLONG_MAX;
    if(k == 1){
        ans = 0;
    }else if(k == 2){
        int med = (d[0] + d[1]) / 2;
        ans = max(abs(d[0] - med), abs(d[1] - med));
    }else{
        int med = (d[0] + d[2]) / 2;
        ans = max(abs(d[0] - med), abs(d[2] - med));
    }

    cout << ans << '\n';
    return 0;
} 