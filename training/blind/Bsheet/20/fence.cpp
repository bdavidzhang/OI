#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<long long>;
using tiii = tuple<int,int,int>;
using vii = vector<vector<int>>;
#define all(v) ((v).begin()),((v).end())
#define sz(v) ((int)((v).size()))


void solve(){
   ll n,k;
   cin >> n >> k;
   vll v(n);
   vll dp(n);
   for(int i = 0 ; i < n; ++i){
        cin >> v[i];
   }

   for(int i = 0; i < k; ++i){
        dp[0] += v[i];
   }

   ll ans = dp[0];
   ll indx = 1;
   for(int i = 1; i < n-k+1; ++i){
        dp[i] = dp[i-1] - v[i-1] + v[i+k-1];
        if(ans > dp[i]){

            ans = dp[i];
            indx = i+1;
        }

   }

   cout << indx << endl;
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
