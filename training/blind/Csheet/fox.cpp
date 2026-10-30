#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<long long>;
using tiii = tuple<int,int,int>;
using vii = vector<vector<int>>;
#define all(v) ((v).begin()),((v).end())
#define sz(v) ((int)((v).size()))

bool isprime(ll a){
    for(ll i = 2; i < sqrt(a)+1;++i){
        if(a % i == 0) return false;
    }
    return true;
}

bool valid(ll a){
    if(isprime(a) && a>5) return false;
    for(ll i = 6; i < sqrt(a)+1; ++i){
        if(a % i == 0)
            if(isprime(i)) return false;
    }
    return true;
}

ll gcd(ll a, ll b){
    if(b == 0) return a;
    if(a < b) swap(a,b);
    return gcd(b, a % b);
}

ll cnt(ll a, ll b){
    ll ans = 0;
    while(a > 1 && a % b == 0){
        a /= b;
        ans++;
    }
    return ans;
}


void solve(){
    ll a,b;
    cin >> a >>b;
    if(a == 1 || b == 1){
        cout << -1 << endl;
        return; 
    }
    
    ll d = gcd(a,b);
    ll x = a/d;
    ll y = b/d;
    if(valid(x) && valid(y)){
        cout << cnt(x,2) + cnt(y,2) + cnt(x,3) + cnt(y,3) + cnt(x,5) + cnt(y,5) << endl;
        return;
    }
    cout << -1 << endl;
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
//I will cause you to ride in triumph on
//the heights of the land
//and to feast on the inheritance of your father Jacob
