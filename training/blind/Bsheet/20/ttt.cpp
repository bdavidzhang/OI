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
   vector<string> g(3);
    for(int i = 0; i< 3; ++i){
        cin >> g[i];
    }

    int x =0;
    int o =0;
    for(int i = 0 ;i < 3; ++i){
        for(int j = 0 ;j < 3; ++j){
            if(g[i][j] == 'O') o++;
            else if(g[i][j] == 'X') x++;
        }
    }

    if(o >= x-1 && o <= x) cout << "yes" << endl;
    else cout << "no" << endl;
}


int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1e9+7; 
    cin >> t;
    for(int i = 0; i < t; ++i){
        if(t == 1e9+7){
            solve();
            break;
        }
        solve();
    }
    return 0;
}
//then you will find joy in the LORD
//I will cause you to ride in triumph on
//the heights of the land
//and to feast on the inheritance of your father Jacob
