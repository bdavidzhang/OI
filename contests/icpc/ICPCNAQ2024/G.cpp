#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<long long>;
using tiii = tuple<int,int,int>;
using vii = vector<vector<int>>;
using ld = long double;
#define all(v) ((v).begin()),((v).end())
#define sz(v) ((int)((v).size()))


void solve(){
   int n;
   cin >> n;
   map<int,vi> mp;
   vi size;
   
   for (int i = 0; i < n; i++) {
    int s,c;
    cin >> s >> c;
    mp[s].push_back(c);
    size.push_back(s);
   }

   ld ans = 0; 
   for(int &s : size){
        vi v = mp[s];
        sort(all(v));
        int t = v.size();
        if(t % 2 == 0){
            for(int i = 0; i < t/2; ++i){
                ans += log(v[t-i]/v[i]);
            }
        }else{
            for(int i = 0; i < t/2-1; ++i){
                ans += log(v[t-1]/v[i]);
            }
            ans += log(v[t/2+1]/v[t/2-1]);
        }
   }
    cout << ans << endl;
}


int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1e9+7; 
    //cin >> t;
    for(int i = 0; i < t; ++i){
        if(t == 1e9+7){
            solve();
            break;
        }
    }
    return 0;
}
//then you will find joy in the LORD
//I will cause you to ride in triumph on
//the heights of the land
//and to feast on the inheritance of your father Jacob
