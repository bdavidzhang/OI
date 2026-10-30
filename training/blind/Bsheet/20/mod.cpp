#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<long long>;
using tiii = tuple<int,int,int>;
using vii = vector<vector<int>>;
#define all(v) ((v).begin()),((v).end())
#define sz(v) ((int)((v).size()))


ll binexp(ll a, ll b, ll m){
    a = a % m;
    ll res = 1;
    while (b > 0){
        if(b & 1) res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;

}


void solve(ll b){
    ll p,m;
    cin >> p >> m;
    cout << binexp(b,p,m) << endl;
    
}


int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll b;
    while(cin >> b){

        solve(b);
    }
    
    return 0;
}
//then you will find joy in the LORD
//I will cause you to ride in triumph on
//the heights of the land
//and to feast on the inheritance of your father Jacob
