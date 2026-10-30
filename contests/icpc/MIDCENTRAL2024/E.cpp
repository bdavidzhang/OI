#include<bits/stdc++.h>
using namespace std;

int n,m, fa[1000009];
int find(int x) {return fa[x] == x?x:fa[x] = find(fa[x]);}
int main () {
    cin >>n>>m;
    int cnt = 0;
    for(int i=1;i<=n;++i) fa[i] = i; 
    if(n == 1) {
        cout << 0 << endl; 
        return 0; 
    }
    for(int i=1;i<=m;++i)  {
        int u,v; cin>>u>>v;
        if(find(u) != find(v)) {
            fa[find(u)] = find(v); 
             ++cnt;
        }
        if(cnt == n - 1) {
            cout << i << endl; 
            break;
        }
    }
    if(cnt < n - 1) cout << -1 << endl; 
    return 0;
}