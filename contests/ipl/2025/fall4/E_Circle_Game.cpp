#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    int d, k;
    cin >> d >> k;

    int x=0,y=0;
    while(true){
        if(x <= y && (x+k)*(x+k) + y*y <= d*d) x +=k;
        else if(x > y && (x)*(x) + (y+k)*(y+k) <= d*d) y +=k;
        else break;
    }
    if(x == y){
        cout << "Utkarsh" << endl;
    }else{
         cout << "Ashish" << endl;
    }
}


signed main(){
    int t;
    cin >> t;
    while(t--){
        solve();    
    }
    return 0;
}