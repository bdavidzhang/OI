#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<long long>;
using tiii = tuple<int,int,int>;
using vii = vector<vector<int>>;


void solve(){
    int n;
    cin >> n;
    vector<bool> occ(n+2,false);

    bool flag = true;
    for(int i = 0; i < n; ++i){
        int x;
        cin >> x;
        occ[x] = true;
        if(i >= 1 && occ[x-1] == false && occ[x+1] == false) flag = false;
    }

    cout << ((flag)? "YES" : "NO") << endl;

}


int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--){
        solve();
    }

    return 0;
}
