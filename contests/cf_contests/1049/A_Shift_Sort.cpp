#include<bits/stdc++.h>
using namespace std;

int main(){


    int tt;
    cin >> tt;
    while(tt--){
        int n;
        cin >> n; 
        string s; 
        cin >> s;
        int cnt = 0;

        for(int i = 0; i < n; ++i){
            if(s[i] == '1') cnt++;
        }

        int cnt0 = 0;
        for(int i = n-1; i > n-1-cnt; --i){
            if(s[i] == '0') cnt0++;
        }
        cout << cnt0 << "\n";

    }
}