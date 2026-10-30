#include<bits/stdc++.h>
using namespace std;



using ll = long long;
using vi = vector<int>;
using vll = vector<long long>;
using tiii = tuple<int,int,int>;
using vii = vector<vector<int>>;

const int MOD = 1e9+7;

ll gcd(int a, int b){
    if(a < b) swap(a,b);
    return (b==0)?a : gcd(b, a%b);
}

ll lcm(vi &c){
   ll ans = c[0];
   for(int i = 1; i < c.size(); ++i){
        ans = ((c[i]*ans)/(gcd(ans,c[i])));
   }
   return ans;
    
}

ll binexp(ll a, ll b, ll p){
    a %= p;
    ll res = 1;
    b %= p-1;
    while(b > 0){
        if(b & 1)res = res * a % p;
        a = a * a % p;
        b >>= 1; 
    }
    return res;

}



void solve(){
    int l,r,k;
    cin >> l >> r >>k;

    
    int key = 9/k+1;


    ll res = (binexp(key,r,MOD)-binexp(key,l,MOD)) % MOD;

    cout << ((res < 0) ? res+MOD : res )<< endl;



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
