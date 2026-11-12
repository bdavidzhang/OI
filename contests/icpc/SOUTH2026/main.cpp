#include<bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
#define fi first 
#define se second

int n,b,p;

bool cmp(pair<int,int> &p1, pair<int,int> &p2){
    return(abs(p1.fi - b) <= abs(p2.fi - b));
}

signed main() {
    cin >> n >> b >> p;
    vector<pair<int,int>> v(n);
    for(int i = 0; i < n; ++i){
        cin >> v[i].fi >> v[i].se;
    }
    sort(all(v),cmp);
    int ans = 0;
    for(auto p : v) cout << p.fi << " " << p.se << endl;
    int cnt = 0;
    
    


    return 0;
}