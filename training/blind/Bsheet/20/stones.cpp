#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<long long>;
using tiii = tuple<int,int,int>;
using vii = vector<vector<int>>;
#define all(v) ((v).begin()),((v).end())
#define sz(v) ((int)((v).size()))


void solve(){
    ll n;
    cin >> n;
    vll v(n+1);
    vll pref(n+1);
    vll u(n+1);
    for(ll i = 1; i <= n; ++i){
        cin >> v[i];
        pref[i] = pref[i-1] + v[i];
    }

    sort(all(v)); 
    for(ll i = 1; i <= n; ++i){
        u[i] = u[i-1] + v[i]; 
    }

    ll m;
    cin >> m;
    for(ll i = 0 ;i  < m; ++i){
        ll t, l, r;
        cin >> t >> l >> r;
        if(t == 1) cout << pref[r]-pref[l-1] << endl;
        else cout << u[r] - u[l-1] << endl;
    
    }
}


int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1e9+7; 
    //cin >> t;
    for(int i = 0; i < t; ++i){
        if(t == 1e9+7){
            solve();
            break;
        }
    }
    return 0;
}
//then you will find joy in the LORD
//I will cause you to ride in triuh on
//the heights of the land
//and to feast on the inheritance of your father Jacob
