//Search - LUOGU
#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<long long>;
using tiii = tuple<int,int,int>;
using vii = vector<vector<int>>;





void solve(){
    int m,n;
    cin >> n >> m;
    vi v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i]; 
    }
    for (int i = 0; i < m; i++) {
        int t;
        cin >> t;
        auto it = lower_bound(v.begin(), v.end(),t);
        if(it == v.end() || *it != t){
            cout << -1 << " ";
        }else{
            cout << 1+distance(v.begin(),it) << " ";    
        }
    }
    cout << endl;

}


int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}


