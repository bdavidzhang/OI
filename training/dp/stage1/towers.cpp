//counting towers.cpp
#include<bits/stdc++.h>
using namespace std;

const int MOD = 1e9+7;
int main(){
    int t;
    cin >> t;
    
    vector<long long> a(1e6+5), b(1e6+5);

    a[0] = b[0] = 0;
    a[1] = 1;
    b[1] = 1;
    for(int i = 2; i < 1e6+5; ++i){
        a[i] = b[i-1] + 2*a[i-1];
        b[i] = a[i-1] + 4*b[i-1]; 
        a[i] %= MOD;
        b[i] %= MOD;
    } 

    while(t--){
        int n;
        cin >> n; 
        cout << ((a[n] + b[n]) % MOD) << endl;
    }
    return 0;
}

