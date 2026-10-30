//more binary exponentiation practice
//UVA OJ - MODEX
#include<bits/stdc++.h>
using namespace std;


long long expo(long long a, long long b, long long MOD){
    if(a == 0) return b == 0;
    long long res = 1; 
    while(b > 0){
        if(b & 1) res = res * a % MOD;
        a = a * a %MOD; 
        b >>= 1;
    } 
    return res;
}


int main(){
    int c;
    cin >> c;
    long long x,y,n;
    while(c--){
        cin >> x >> y >> n;
        cout << expo(x,y,n) % n << endl;         
    }
    int holder;
    cin >> holder;
    return 0;
}
