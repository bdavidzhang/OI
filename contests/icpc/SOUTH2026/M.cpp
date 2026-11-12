#include<bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
int n, a[200009],b[200009], bit[100009];
struct dat{int id, x,y;};
vector<dat>q[100009];
vector<int>c[100009];
void add(int x,int y) {
    for(;x<=100000;x += x & -x) bit[x] += y;
}
int ask(int x) {
    int ans = 0; 
    for(;x; x-=x&-x) ans += bit[x];
    return ans;
}
int range(int l,int r) {return ask(r) - ask(l - 1);}
signed main() {
    cin >> n;
    for(int i=1;i<=n;++i) {
        cin >> a[i] >> b[i]; 
        int r1 = min(100000ll, a[i]  + 100);
        q[r1].push_back((dat){i, max(1ll,b[i] - 100), min(100000ll, b[i] + 100)}) ; 
        c[a[i]].push_back(b[i]);
    }

    int ans = 0; 
    for(int x=1;x<=100000;++x) {
        for(auto y : c[x]) add(y,1);
        for(auto [id,x,y] : q[x]) if(range(y,x) == 0){
            ans = id;
        }

        if(x >= 201) 
            for(auto y : c[x - 200]) add(y,-1);
    }
    cout << ans << endl; 
    return 0; 
}