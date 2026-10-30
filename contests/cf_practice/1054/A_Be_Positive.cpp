#include<bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int cntn1 = 0;
        int cnt = 0;
        for(int i = 0 ; i < n; ++i){
            int x;
            cin >> x;
            if(x == 0) cnt++;
            if(x == -1) cntn1++;
        }
        cout << cnt+(cntn1 % 2 == 0 ? 0 : 2) << endl;
    }

        
    
    return 0;
}