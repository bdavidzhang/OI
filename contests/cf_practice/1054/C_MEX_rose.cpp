#include<bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        vector<int> v(n);
        vector<int> less(k,1);
        int cntk = 0;
        for(int i = 0; i < n; ++i){
            cin >> v[i];
            if(v[i] < k) less[v[i]] = 0;
            if(v[i] == k) cntk++;
        }

        int cntless = 0;
        for(int i = 0; i < k; ++i) cntless+=less[i];
        cout << max(cntless,cntk) << endl;
    }

        
    
    return 0;
}