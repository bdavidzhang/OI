#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<long long>;
using tiii = tuple<int,int,int>;
using vii = vector<vector<int>>;
using ld = long double;
using pii = pair<int,int>;
using vb = vector<bool>;
#define all(v) ((v).begin()),((v).end())
#define sz(v) ((int)((v).size()))
#define fi first
#define se second
#define mp make_pair
#define pb push_back


void solve(){
    int n;
    cin >> n;
    vi v(n);
    for(int i = 0;i < n; ++i) cin >> v[i];

    vi dp;
    dp.pb(v[0]);
    dp.pb(v[0]*-1);
    for(int i = 1; i < n; ++i){
        ll t = sz(dp);
        for(int j = 0; j < t; ++j){
            dp.pb(dp[j]+v[i]);
            dp.pb(dp[j]-v[i]);
        }
        dp.pb(v[i]);
        dp.pb(v[i]*-1);
    } 


    bool flag = false;
    for(int x : dp){
        if(x == 0) flag = true;
    }

    if(flag) cout << "YES" << endl;
    else cout << "NO" << endl;
    
    

    // set
    // vector
    // + curr, - curr
    // curr + that
    // curr - that
    // set += vcector
    
}


int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tk = 1;
    cin >> tk;
    for(int i = 0; i < tk; ++i){
        solve();
    }
    return 0;
}
//then you will find joy in the LORD
//I will cause you to ride in triumph on
//the heights of the land
//and to feast on the inheritance of your father Jacob
