#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<long long>;
using tiii = tuple<int,int,int>;
using tlll = tuple<ll, ll, ll>;
void solve(){
    ll x,y,z,V;
    cin >> x >> y >> z >> V;
    vector<tlll> dims;
    vll cnt;

    for(int i = 1; i <= x; ++i){
        for(int j = 1; j <= y; ++j){
            if(static_cast<double>(V)/(i*j) == V/(i*j)){
                dims.push_back({i,j,V/(i*j)}); 
            } 
        } 
    }

    //brute force = O(2000^4) not going to work

    ll max = 0;
    for(auto p : dims){
        ll res = (x-get<0>(p)+1)*(y-get<1>(p)+1)*(z-get<2>(p)+1);
        cnt.push_back(res);
        if(res > max) max = res;
    }

    


    cout << max << endl;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--){
        solve(); 
    }


    return 0;
}
