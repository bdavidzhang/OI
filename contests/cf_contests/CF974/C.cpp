#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--){
        long long n;
        cin >> n;
        long long sum = 0;
        int cur;
        vector<int> v(n);
        for(int i = 0; i < n; ++i){
            cin >> v[i];
            sum += v[i];
        }
        sort(v.begin(),v.end());
        long long x = max(static_cast<long long>(0),n*2*v[(n/2)]-sum+1);
        cout << ((n > 2)? x : -1) << endl;
         
    }



    return 0;
}
