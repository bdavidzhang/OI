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

const int MAXN = 4e5+10;


void solve(){
   int n, m;
   cin >> n >> m;
   v<vi> g(MAXN);
   for(int i = 1; i < 2*m; ++i){
       g[i].push_back(i-1);
       g[i].push_back(2*i);
   }

   vi d(MAXN);
   vi 
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
