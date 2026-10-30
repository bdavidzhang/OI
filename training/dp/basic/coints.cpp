#include<bits/stdc++.h>

using namespace std;

int main(){
    
    int n,x;
    cin >> n >> x;
    
    vector<int> coins;
    
    for(int i = 0; i < n; ++i){
        int a; 
        cin >> a;
        coins.push_back(a);
    }

    sort(coins.begin(),coins.end());

    vector<int> ways(x+1,1E9);
    ways[0] = 0;

    for(int i = 1; i <= x; ++i){
        for(int j = 0; j < n; ++j){
            if(i >= coins[j])
               ways[i] = min(ways[i],ways[i-coins[j]] + 1);
            else
                break;
        }
    }

    if(ways[x] == 1E9) cout << -1 << endl;
    else cout << ways[x] << endl;
    return 0;
}
