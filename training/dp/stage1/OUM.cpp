//Modular inverse practice, which isn't really dp
//UVA OJ - Leading and trailing
#include<bits/stdc++.h>
using namespace std;

long long expo(long long a, long long b, long long m){
    if(a == 0) return b == 0;
    long long ans = 1;
    while(b > 0){
        if(b & 1) ans = (a*ans) % m;
        a = (a * a) % m;
        b >>= 1;
    }
    
    return ans;
}

const int MOD = 1e9 + 7;

//(p-1)! = -1 mod(p) -> Wilson's theorem




int main(){    
   
    int t;
    cin >> t;
    while(t--){
        long long sum = 0;
        int n;
        cin >> n;
        vector<int> v(n);
        for(int i = 0; i < n; ++i){
            cin >> v[i];
            sum += v[i];
        }      
        
        cout << solve(sum, v, n);


    }
   
    return 0;
}
