#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, r, d;
    long long x = n - (r-1)*d;
    if(x < d) cout << -1 << endl;
    else cout << x << endl;


     return 0;
}
