#include<bits/stdc++.h>

using namespace std;


const int MOD = 1e9+7;


int main(){
    
    int n, x;
    cin >> n >> x;

    vector<int> coins(n);

    for(int i = 0;i < n; ++i){
        cin >> coins[i];
    }

    sort(coins.begin(),coins.end());

    vector<int> ways(x+1);

    ways[0] = 1;
    
    for(int i = 0; i <n; ++i){
        for(int j = coins[i]; j <= x; j++){
            ways[j] += ways[j-coins[i]];
            ways[j] %= MOD;
        }
    }

    cout << ways[x] % MOD<< endl;

    return 0;
}
