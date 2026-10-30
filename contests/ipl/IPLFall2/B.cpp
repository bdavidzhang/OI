#include<bits/stdc++.h>
using namespace std;

int main(){

    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int ans = 1e9;
        for(int i = 1;i <= sqrt(n)+1; ++i){
            int vals = (i-1) + ceil(n/i);
            if(n % i == 0) vals--;
            ans = min(ans,vals);  
        }    
        cout << ans << endl;
    }
    return 0;
}
