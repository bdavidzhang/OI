#include<bits/stdc++.h>
using namespace std;

#define int long long

const int MOD = 1e9 + 7;


int pow(int a, int b, int m){
    //binexp for a^b mod m
    int res = 1;
    while(b){
        if(b & 1){
            res = (res % m) * (a % m) % m;
        }
        a = (a * a) % m;
        b >>= 1;
    }
    return res % m;
}


signed main(){
    // cin.tie(nullptr)->sync_with_stdio(false);

    

    int t;
    cin >> t;
    while (t--)
    {
        int l,r,k; 
        cin >> l >> r >> k;

        cout << (pow(9/k+1,r,MOD) % MOD - pow(9/k+1,l,MOD) % MOD + MOD) % MOD << endl;
    }

    return 0;
}