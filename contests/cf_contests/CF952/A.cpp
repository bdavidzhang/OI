#include<bits/stdc++.h>
using namespace std;


void solve(){
    string a, b;
    cin >> a >> b;
    char t;
    t = a[0];
    a[0] = b[0];
    b[0] = t;
    cout << a << " " << b << endl; 
}



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--){
        solve(); 
    }


    return 0;
}
