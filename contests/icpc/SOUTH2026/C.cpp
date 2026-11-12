#include<bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
int n,m;
string s[809];
bool xa[809], xb[809];
signed main() {
    cin >>n>>m;
    for(int i=1;i<=n;++i) cin >>s[i], s[i] = " " + s[i];
    int ans = 0; 
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j)
            if(s[i][j] =='*') {
                if(!xa[i] && j < m && s[i][j + 1] =='*') 
                    continue;
                if(!xb[j] && i < n && s[i+1][j] =='*')
                    continue;
                ++ans, xa[i] = xb[j] = 1;    
            }
    cout << ans << endl; 
    return 0; 
}