#include<bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> v(n);
        for(int i = 0; i < n; ++i){
            cin >> v[i];
        }

        sort(v.begin(),v.end());

        int ans = 0;
        for(int i = 0; i < n; i += 2){
            ans = max(ans,v[i+1]-v[i]);
        }
        cout << ans << endl;
    }

        
    
    return 0;
}