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
   int cnt = 0;
   vector<int> pos;
   for(int i = 0; i < n; ++i){
        if(s[i] == '1'){
            cnt++;
            pos.pb(i);
        }
   }
   ll ans = 0;
   ll beat = n + cnt;
   int prev = 0;
   int cur = 0;
   for(int i = 0; i < cnt; ++i){
        cur = pos[i];
        ans += (cur-prev)+1;
        if(i > 0){
            if(ans + (cur-prev)+1 > beat){
                beat = ans+cur-prev+1;
            }
        }
        prev = cur;
   }
   ans += (n-1)-cur;
   if(ans > beat){
        beat = ans;
   }

   cout << beat << endl; 
}


int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tk = 1;
    cin >> tk;
    for(int i = 0; i < tk; ++i){
        solve();
    }
    return 0;
}
//then you will find joy in the LORD
//I will cause you to ride in triumph on
//the heights of the land
//and to feast on the inheritance of your father Jacob
