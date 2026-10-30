#include<bits/stdc++.h>
using namespace std;


int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<int> b(3);
    int tot = 0;
    for(auto& x : b){
     cin >> x;
     tot += x;
    }
    sort(b.begin(),b.end());
    int ans = 3 * (n / tot); 
    int left = n - (n / tot) * tot;
    // cout << ans << endl;
    // cout << left << endl;
    if(left >= b[0]){
        if(left >= b[0] + b[1]) ans += 2;
        else ans++;
    }
    
    cout << ans << endl;
    

    return 0;
}