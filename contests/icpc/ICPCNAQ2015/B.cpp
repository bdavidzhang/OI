#include<bits/stdc++.h>
using namespace std;

using ld = long double;
using ll = long long;

vector<ll> fact(20);

void init(){
    fact[0] = fact[1] = 1;
    for(int i = 2; i <= 19; ++i){
        fact[i] = fact[i-1] * i; 
    }
}

ll nCr(int n, int r){
    return fact[n]/fact[r]/fact[n-r];
}



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    init();

    int n;
    cin >> n;
    while(n--){
        int r,s,x,y,w;
        cin >> r >> s >> x >> y >> w;  
    
        ld p = ld(s-r+1)/s;
        ld q = 1-p;

        ld sum = 0;
        for(int i = x; i <= y; ++i){
            sum += nCr(y, i)*pow(p,i)*pow(q,y-i); 
        }

        ld exped = w*sum;
        if(exped > 1) cout << "yes" <<endl; 
        else cout << "no" << endl;
    }

    return 0;
}
