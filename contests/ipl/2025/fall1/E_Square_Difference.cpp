#include<bits/stdc++.h>

using namespace std;

// bool isprime(int x){
//     if(x < 2) return false;
//     for(int i=2;i*i<=x;i++){
//         if(x % i == 0) return false;
//     }
//     return true;
// }

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int tt;
    cin >> tt;
    while (tt--){
        int a,b; 
        cin >> a >> b;
        // if(isprime(a*a - b*b)){
        //     cout << "YES" << endl;
        // } else {
        //     cout << "NO" << endl;
        // }
        if(a == b+1){
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}