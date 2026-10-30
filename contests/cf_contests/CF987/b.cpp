#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2e5+5;
bool dp[MAXN];
int arr[MAXN];
void solve(){
    int n;
    cin >> n;
    for(int i = 1; i <= n; ++i){
        cin >> arr[i];
    }
    dp[1] = true;
    dp[2] = true;
    for(int i = 3; i <=n; ++i){
        if(arr[i] == i) dp[i] = arr[i-1];
        else if(arr[i-1] == i && arr[i] == i-1) dp[i] = arr[i-2];
        else dp[i] = false;
    }
    if(dp[n]) cout << "YES";
    else cout << "NO";


}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }


}