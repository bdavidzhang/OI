#include<bits/stdc++.h>
using namespace std;


int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);


    int n,k;
    cin >> n >> k;
    string s;
    cin >> s;
    s = "R" + s;
    int cnt = 0;
    for(int i = 1; i <= n; ++i){
        if(s[i] == s[i-1]) cnt++;
    }
    cout << max(k-cnt, 0) << endl;



    return 0;
}