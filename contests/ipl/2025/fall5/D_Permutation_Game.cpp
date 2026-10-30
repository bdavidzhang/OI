#include<bits/stdc++.h>
using namespace std;

using ll = long long;


void solve(){
    ll n,k,B,S;
    cin >> n >> k >> B >> S;
    vector<int> p(n+1),a(n+1);
    for(int i = 1; i <= n; ++i) cin >> p[i];
    for(int i = 1; i <= n; ++i) cin >> a[i];

    ll cnt = 1;
    ll travel = 0;
    ll ans1 = a[B]*k;
    ll i = B;
    do{
        travel += a[i];
        i = p[i];
        ans1 = max(ans1, travel+1LL*a[i]*(k-cnt)); 
        cnt++;
    }while(i != B && cnt <= k);

    cnt = 1;
    travel = 0;
    ll ans2 = a[S]*k;
    i = S;
    do{
        travel += a[i];
        i = p[i];
        ans2 = max(ans2, travel+1LL*a[i]*(k-cnt)); 
        cnt++;
    }while(i != S && cnt <= k); 
    // cout << ans1 << " " << ans2 << endl;

    cout << ((ans1 > ans2) ? "Bodya" : (ans2 > ans1) ? "Sasha" : "Draw") << endl;
}


signed main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }


    return 0;
}