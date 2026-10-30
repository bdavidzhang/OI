#include<bits/stdc++.h>
using namespace std;

#define int long long

signed main(){
        int t;
        cin >> t;
        while(t--){
        int n;
        cin >> n;
        string s;
        cin >> s;
        int cnta = 0,cntb = 0;
        vector<int> a,b;
        for(int i = 0; i < n; ++i){
            if(s[i] == 'a') a.push_back(i-cnta++);
            else b.push_back(i-cntb++);
        }       

        
        int ansa = 0;
        for(int i = 0; i < cnta; ++i){
            ansa += abs(a[i] - a[cnta/2]);  
        }
        int ansb = 0;
        for(int i = 0; i < cntb; ++i){
            ansb += abs(b[i] - b[cntb/2]);  
        }
        cout << min(ansa,ansb) << endl; 

    }
    return 0;
}