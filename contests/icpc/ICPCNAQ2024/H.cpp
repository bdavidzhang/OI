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
    int n;
    vecotr<pair<int,int>> par(n);
    vector<char> c(n);
    for(int i = 0; i < n; ++i){
        int p1,p2;
        cin >> p1 >> p2 >> c[i];
        par[i] = make_pair(p1,p2);
    }

    for(int i = 0 ;i < n; ++i){
        if(par[i].first == 0 && par[i].second == 0){
            pass;
        }
        
    }
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
