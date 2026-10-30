//codeforces - Alice and presents
#include<bits/stdc++.h>
using namespace std;

const int MOD = 1e9+7;

int expo(long long a, long long b){
    if(a == 0) return b == 0;
    int ans = 1;
    while(b){
        if(b&1) ans = (ans*a)%MOD;
        b >>= 1LL;
        a = (a*a)%MOD; 
    }
    return ans;
}


int main(){
    int n,m;
    cin >> n >> m;

    cout << expo((expo(2,m)-1),n) % MOD << endl;    
     

    return 0;
}
