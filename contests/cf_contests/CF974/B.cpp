#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--){
        long long n, k;
        cin >> n >> k;
        long long sum = 0;


        sum = (n-k+1+n)*(k)/2;
            
        cout << ((sum%2 == 0)? "YES" : "NO" )<< endl;
    
    }



    return 0;
}
