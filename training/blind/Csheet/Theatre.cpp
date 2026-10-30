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

ll comb(int a, int b){
   if(a == b) return 1;
   else if (b == 0) return 1;
   return a*comb(a-1,b-1)/b; 
}

void solve(){
    int n, m, k;
    cin >> n >> m >> k;
    ll ans = 0;
    for(int i = 4; i <= k-1; ++i){
        ans += comb(n,i)*comb(m,(k-i));
    }
    cout << ans << endl; 
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
