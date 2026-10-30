#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    int x;
    cin >> n >> x;
    int maxa = -1;
    bool found_x = false; 

    for(int i = 0; i < n; ++i){
        int a;
        cin >> a;
        if(a == x){
            found_x = true; 
        }
        maxa = max(maxa, a);
    }

    if (found_x) {
        cout << 1 << endl;
    } else {
        cout << max(2, (x + maxa - 1) / maxa) << endl;
    }
}


int main(){
    int t;
    cin >> t;
    while(t--){
      solve();    
    }
    return 0;
}