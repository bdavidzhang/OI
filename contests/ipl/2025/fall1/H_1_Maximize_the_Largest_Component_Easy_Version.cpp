#include<bits/stdc++.h>
using namespace std;



void solve(){
    int n,m;
    cin >> n >> m;
    vector<string> grid(n);
    for(int i = 0; i < n; ++i){
        cin >> grid[i];
    }

    vector<vector<bool>> visited(n,vector<bool>(m, false));
    vector<vector<int>> id(n,vector<int>(m,0));
    vector<int> sizes;

    current_id_cnt = 1;



}


int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }

    return 0;
}