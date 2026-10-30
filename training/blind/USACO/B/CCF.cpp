#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<long long>;
using tiii = tuple<int,int,int>;
using vii = vector<vector<int>>;
using ld = long double;
using pii = pair<int,int>;
using vb = vector<bool>;
#define all(v) ((v).begin()),((v).end())
#define sz(v) ((int)((v).size()))
#define fi first
#define se second
#define mp make_pair
#define pb push_back


void solve(){
   int n, m;
    cin >> n >> m;
    vll c(n);
    for (int i = 0; i < n; i++) {
       cin >> c[i]; 
    }
    for (int i = 0; i < m; i++) {
        ll hi;
        cin >> hi;
        ll lo = 0;
        for (int j = 0; j < n; j++) {
           if(lo <= hi){
               ll t = c[j];
               c[j] += max((ll) 0,(ll) min(c[j]-lo,hi-lo));
               lo = max(lo,t);
           }    
        }

    }
    for(int i = 0; i < n; ++i) cout << c[i] << endl;
}


int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tk = 1;
    //cin >> tk;
    for(int i = 0; i < tk; ++i){
        solve();
    }
    return 0;
}
//then you will find joy in the LORD
//I will cause you to ride in triumph on
//the heights of the land
//and to feast on the inheritance of your father Jacob
