//more binary exponentiation practice
//UVA OJ - BIG MOD
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
   
    int B,P,M;
    
    while(cin>>B>>P>>M)
        cout<<expo(B,P,M) % M<<endl;


    return 0;
}
