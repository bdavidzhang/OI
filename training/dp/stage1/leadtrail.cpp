//more binary exponentiation practice
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


int main(){    
   
    int t;
    cin >> t;
    long long n,k;
    while(t--){
        cin >> n >> k; 
        int trailing = expo(n,k,1000) % 1000;
        double power = k*log10(n);
        int leading = floor(100.0*pow(10,(power-floor(power))));
        cout << leading << "..." << trailing << endl;
    }
   
    return 0;
}
