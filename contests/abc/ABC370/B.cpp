#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    
    vector<vector<int> > a(n+1,vector<int>(n+1));
    vector<int> val(n+1);

    for (int i = 1; i <= n; ++i){
        for(int j = 1; j <= i; ++j){
            cin >> a[i][j]; 
        } 
    }

    int cur = 1;
    for(int i = 1; i <= n; ++i){
        cur = cur >= i ? a[cur][i] : a[i][cur]; 
    }
    
    cout << cur <<endl;

    return 0;
}
