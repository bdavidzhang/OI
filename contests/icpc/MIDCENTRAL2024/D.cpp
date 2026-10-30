#include<bits/stdc++.h>
using namespace std; 


int n,m,st1, st2, st3, st4; 
struct dat {
    int r1,c1,r2,c2;
    bool a,b,c,d;
}
string a[19][19];
queue<dat> q; 
int main() {
    cin >> n >> m;
    for(int i=1;i<=n;++i) {
        cin >> a[i];
        a[i] = " " + a[i];
        for(int j=1;j<=m;++j) {
            if(a[i][j] == 'S') {
                if(st1 > 0) st3 = i, st4 = j;
                else st1 = i, st2 = j; 
            }
        }
    }
    
    return 0; 
}