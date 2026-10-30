#include<bits/stdc++.h>

using namespace std;
using ll = long long;
using vll =vector<ll>;

ll val(vll &arr, int id, bool on){
    if(id == arr.size()-1){
        if(on) return 2*arr[id];
        else return arr[id]; 
    }else{
        if(on)return max(val(arr,id+1,!on) + 2*arr[id], val(arr,id+1,on));
        else return max(val(arr,id+1,!on) + arr[id], val(arr, id+1, on));
    }
}


//recursion solution works, now dp

int main(){
    int n;
    cin >> n;
    vll arr(n);

    vector<vll> dp(2, vll(n));//dp 

    for(int i = 0;i < n; ++i) cin>> arr[i];
    
    ll sum = 0;
    
    dp[0][n-1] = arr[n-1];
    dp[1][n-1] = 2*arr[n-1];

    //want to find dp[0][0]

    for(int i = n-2; i >= 0; --i){
        dp[0][i] = max(dp[1][i+1]+arr[i],dp[0][i+1]);
        dp[1][i] = max(dp[0][i+1]+2*arr[i],dp[1][i+1]);
    }


    cout << dp[0][0] << endl;

    return 0;
}
