#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        if(n > m) swap(n,m);
        cout << (m % n == 0 ? "YES" : "NO") << endl;
    }
    return 0;
}