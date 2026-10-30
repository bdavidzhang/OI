#include<bits/stdc++.h>
using namespace std;

int main(){

    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int t;
    cin >> t;
    while(t--){
       int n, x;
       cin >> n >> x;
       
       cout << (n <= 2? 1 : ceil((n-2)/static_cast<double>(x)) + 1) << endl;  
    
    }
    return 0;
}
