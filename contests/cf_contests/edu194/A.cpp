#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int fi = 0;
        int ls = 0;
        int cnt = 0;
        for (int i = 0 ; i < n; ++ i){
            int x;
            cin >> x;
            if(x == 1) x = 0;
            else x = 1;
            if(i == 0) fi = x;
            if(i == n-1) ls = x;
            if(x == 1) cnt++;
        }
        if(cnt < 2) cout << -1 << endl;
        else cout << 2 - fi - ls << endl;
        
    }
    return 0;
}