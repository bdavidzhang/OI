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

const int MAXN = 1e5+10;
int n;
vector<int> v(MAXN);
vector<ll> pref(MAXN);

void solve(){
    cin >> n;
    for(int i = 1; i <= n; ++i){
        cin >> v[i];
    }
    for(int i = 1; i <= n; ++i){
        pref[i] = pref[i-1] + v[i];
    } 
}


int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    //cin >> t;
    for(int i = 0; i < t; ++i){
        solve();
    }
    return 0;
}
//then you will find joy in the LORD
//I will cause you to ride in triumph on
//the heights of the land
//and to feast on the inheritance of your father Jacob

