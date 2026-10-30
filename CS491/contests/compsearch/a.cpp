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


bool find(string s){
    for(int i = 0; i < sz(s)-2; ++i){
        if(s[i] == '4' && s[i+1] == '9' && s[i+2] =='5') return true;
    }
    return false;
}

void solve(){
    ll l, r;
    cin >> l >> r;
    ll cnt = 0;
    string s;
    for (ll i = l; i <= r; ++i){
        s = to_string(i);
        if(find(s)) cnt++;
    }
    cout << cnt << endl;
    
}


int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tk = 1;
    //cin >> tk;
    for(int i = 0; i < tk; ++i){
        solve();
    }
    return 0;
}
//then you will find joy in the LORD
//I will cause you to ride in triumph on
//the heights of the land
//and to feast on the inheritance of your father Jacob
