#include<bits/stdc++.h>
using namespace std;

string s; 
int sum[3];
int main() {
    cin >> s;
    int ans = 0;
    for(auto c : s) { 
        int w  = c-'A', mn = 2e9;
        ++ sum[w];
        for(int i=0;i<3;++i) mn =min(mn, sum[i]);
        for(int i=0;i<3;++i) sum[i]-=mn;
        for(int i=0;i<3;++i) ans =max(ans, sum[i]);
    }
    cout << ans << endl; 
    return 0; 
}