//SPOJ LVADER
#include<bits/stdc++.h>
using namespace std;

const int MOD = 1e9+7;
const int MAXN = 1e5+10;

using ll = long long;

vector<ll> fact(MAXN);
vector<ll> p2(MAXN);

void init(){
    fact[0] = fact[1] = 1;
    for(int i = 2; i < MAXN; ++i){
        fact[i] = fact[i-1] * i;
        fact[i] %= MOD;
    }

    p2[0] = 1;
    for(int i= 1; i < MAXN; ++i){
        p2[i] = p2[i-1] * 2;  
        p2[i] %= MOD;
    }
}

ll binpow(ll a, ll b){
    a %= MOD;
    b = b % (MOD-1);
    ll res = 1;
    while(b > 0){
        if(b & 1){
            res *= a % MOD;
            res %= MOD;
        }
        a = a*a % MOD;
        b >>= 1;
    }   
    return res;

}


ll inv(ll k){
    return binpow(k, MOD-2); 
}


ll ncr(ll a, ll b){
    return (fact[a] * inv(fact[b])) % MOD * inv(fact[a-b]) % MOD;

}


ll dnn(ll x, ll y){
    ll sum = 0;
    for(int k = 0; k <= min(x,y); ++k){
        sum += (ncr(x,k) * ncr(y,k)) % MOD * p2[k];
        sum %= MOD;
    }
    return sum;

}

int main(){

    int t;
    cin >> t;
    init();

    for(int i = 1; i <= t; ++i){
        ll a,b,c,d;
        cin >> a >> b >> c >> d; 

        cout << "Case " << i << ": "<< dnn(c-a, d-b) << endl;

    }
    return 0;
}




