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

const int MAXN = 1e5+10;
int n,m,k;
vll v(MAXN);
vll d(MAXN);
vector<tuple<ll,ll,ll>> op(MAXN);
vll q(MAXN);

void solve(){
   cin >> n >> m >> k; 
   for(int i = 1 ;i <= n ;++i){
        cin >> v[i];
        d[i] = v[i]-v[i-1];
   }
   cout << endl;
   for(int i = 1; i <= m; ++i){
       int r,l;
       ll val;
       cin >> l >> r >> val;
       op[i] = make_tuple(l,r,val);
   }
   for(int i = 0; i < k; ++i){
       int x, y;
       cin >> x >> y;
       q[x]++;
       q[y+1]--;
   }
   for(int i = 1; i <= n; ++i){
        q[i] = q[i-1] + q[i];
        d[get<0>(op[i])] += q[i]*get<2>(op[i]);
        d[get<1>(op[i])+1] -= q[i]*get<2>(op[i]);
   }
   for(int i = 1; i <= n; ++i){
        d[i] = d[i-1] + d[i];
        cout << d[i] << " ";
   }
   cout << endl;
   
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
