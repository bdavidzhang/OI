#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;

int n,m, f[509][509], g[509][509]; 
string a[509];
int main () {
    cin >> n >> m;
    for(int i=1;i<=n;++i) {
        cin>>a[i];
        a[i] = " " + a[i];
    }
    int ans = 0 ;
    for(int i=1;i<=n;++i){
        for(int j=1;j<=m;++j) {
            int k = 0, len = 1; 
            while(1) {
                ++k;
                int l = i - k, r = i + k;
                if(l < 1 || r > n || a[l][j] != a[r][j])  {--k; break;}
                len += 2;
            }
            for(int l = i - k; l <= i + k; ++l)
                f[l][j] = max(f[l][j], len);
            k = -1, len = 0 ;
            while(1) {
                ++k;
                int l = i - k, r = i + 1 + k;
                if(l < 1 || r > n || a[l][j] != a[r][j]) {--k; break;}
                len += 2;
            }
            for(int l = i - k; l <= i + 1 + k; ++l)
                f[l][j] = max(f[l][j], len);
            k = 0 ,len = 1;
            while(1) {
                ++k;
                int l = j - k, r = j + k;
                if(j < 1 || j > m|| a[i][l] != a[i][r])  {--k; break;}
                len += 2;
            }
            for(int l = j - k; l <= j + k; ++l)
                g[i][l] = max(g[i][l], len);
            k = -1 ,len = 0;
            while(1) {
                ++k;
                int l = j - k, r = j + 1 + k;
                if(j < 1 || j > m || a[i][l] != a[i][r])  {--k; break;}
                len += 2;
            }
            for(int l = j - k; l <= j + k + 1; ++l)
                g[i][l] = max(g[i][l], len);
        }
        
    }
    for (int i=1;i<=n;++i)
        for(int j=1;j<=m;++j)
            ans = max(ans, f[i][j] * g[i][j]);
    cout << ans << endl; 
    return 0; 
}