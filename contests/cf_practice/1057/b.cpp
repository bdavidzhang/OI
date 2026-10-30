#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int x,y,z;
        cin >> x >> y >> z;
        int a1 = x&y, a2 = y&z, a3 = z&x, A=x&y&z;
        if(a1 == A && a2 == A && a3 == A) cout << "YES" << endl;
        else cout << "NO" <<endl;
    }
    return 0;
}