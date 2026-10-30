#include <bits/stdc++.h>
using namespace std;


int pow(int a, int b,int MOD){
    int res = 1;
    int cur = a;
    while(b){
        if(b & 1) res = res * cur % MOD;
        b >>=1;
        cur = cur * cur % MOD;
    }
    return res;
}



int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("fast_out.txt", "w", stdout);  // change to "brute_out.txt" for brute.cpp
#endif

    int n,k;
    cin >> n >> k;

    int a = n/k;
    int b = n % k;

    const int MOD = 1e9+7;
    int res = 1;
    res *= pow(a+1,b,MOD);
    res *= pow(a,k-b,MOD);

    cout << res << endl;

}
