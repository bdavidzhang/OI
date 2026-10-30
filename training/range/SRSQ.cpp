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

const int MAXN = 2e5+10;
int n, q;
vll Tr(MAXN);

void add(int i, ll a){
    while(i <= n){
        Tr[i] += a;
        i += i & -i;
    }
}

ll sum(int i){
    ll ans = 0;
    while(i > 0){
       ans += Tr[i];
        i -= i & -i;
    }
    return ans;
}

void solve(){
   cin >> n >> q;
   for (int i = 1; i < n+1; i++) {
      int x;
      cin >> x;
      add(i,x);
   }
   for(int i = 0; i < q; ++i){
        int a,b;
        cin >> a >> b;
        cout << sum(b) - sum(a-1) << endl;
  }
}


int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    //cin >> t;
    for(int i = 0; i < t; ++i){
        solve();
    }
    return 0;
}
//then you will find joy in the LORD
//I will cause you to ride in triumph on
//the heights of the land
//and to feast on the inheritance of your father Jacob
