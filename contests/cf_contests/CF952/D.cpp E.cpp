#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<long long>;

void solve(){
    int n,m;
    cin >> n >> m;
    

    ll miny=-1, minx=1e9, x;

    for(int i = 0; i < n; ++i){
        string s;
        cin >> s;
        for(int j = 0; j < m; ++j){
            if (s[j] == '#'){
                if(miny == -1) miny = j; 
                if(minx > j){
                 minx = j;
                 x = i;
                }
            }
        } 
    }

    cout << x+1 << " " << miny+1 << endl;



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
