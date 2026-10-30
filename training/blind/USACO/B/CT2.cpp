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
   int n;
   cin >> n;
   string s;
   cin >> s;
   vi v;
   int cnt = 0;
   char prev = '0';
   bool lbound = false;
   bool rbound = false;
   for(int i = 0; i < n; ++i){
       if(s[i] == '1'){
            if(i == 0) lbound = true;
            if(i == n-1) rbound = true;
            cnt++;
       }else{
          if(prev == '1'){
              v.pb(cnt);
            cnt = 0;
          }
       }
       prev = s[i];
   }
   if(prev == '1') v.pb(cnt);

   ll ans = 1e9;
   int indx = -1;
   ll tot = 0;
   for(int i = 0; i < sz(v); ++i){
       if(ans > min){
            ans = min;
            indx = i;
       }
       if(i == sz(v)-1 && v[i] == min) indx = i;
       tot += v[i];
   }
  if(ans >= 3){
       if(ans % 2 == 1) tot -= (ll) sz(v) * (ans-1);
       else tot -= (ll) sz(v) * (ans-2);
   }

  cout << tot << endl; 

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
