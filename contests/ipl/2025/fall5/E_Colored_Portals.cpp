#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using t4 = array<ll,4>;  //4 tuples
const ll INF = 1e17;

map<char, int> color_int = {
    {'B',0},{'G',1},{'R',2},{'Y',3}
};

void solve(){
    int n, q;
    cin >> n >> q;

    vector<pair<int, int> > a(n);//color
    vector<t4> prev(n,{-1,-1,-1,-1});
    vector<t4> next(n,{n,n,n,n});

    for(int i = 0;i < n; i++){
        string s;
        cin >> s;
        a[i].first = color_int[s[0]];
        a[i].second = color_int[s[1]];
    }

    t4 near = {-1,-1,-1,-1}; //nearest for each color
    for(int i = 0; i < n; ++i){
        auto [c1,c2] = a[i];
        prev[i][c1] = i; prev[i][c2] = i;
        int p1 = near[c1], p2 = near[c2]; //nearest cities with color c1,c2
        for(int color = 0; color < 4; ++color){
            //for c3 and c4, this is prev[p1][color] or -1
            if(p1 != -1) prev[i][color] = max(prev[i][color],prev[p1][color]);
            if(p2 != -1) prev[i][color] = max(prev[i][color],prev[p2][color]);
        }
        near[c1] = i; near[c2] = i;//update near colors
    }

    near = {n,n,n,n}; //nearest now for next
    for(int i = n-1; i >= 0; --i){
        auto [c1,c2] = a[i];
        next[i][c1] = next[i][c2] = i;
        int n1 = near[c1],n2 = near[c2];
        for(int color = 0; color < 4; ++color){
            if(n1 != n) next[i][color] = min(next[i][color],next[n1][color]);
            if(n2 != n) next[i][color] = min(next[i][color],next[n2][color]);
        }
        near[c1] = near[c2] = i;
    } 

    auto dist = [&](int i, int j) -> ll {
        if(i == -1 || i == n) return INF;
        if(j == -1 || j == n) return INF;
        return abs(i-j);
    };


    while(q--){
        int i,j;
        cin >> i >> j;
        i--;j--;
        ll ans = INF;
        for(int color = 0; color < 4; ++color){
            int pi = prev[i][color], ni = next[i][color];
            int pj = prev[j][color], nj = next[j][color];

            // cout << pi << " " << ni << " " << pj << " " << nj << endl;
            
            ll ans1 = dist(i,pi) + dist(pi,pj) + dist(pj,j);
            ll ans2 = dist(i,pi) + dist(pi,nj) + dist(nj,j);
            ll ans3 = dist(i,ni) + dist(ni,pj) + dist(pj,j);
            ll ans4 = dist(i,ni) + dist(ni,nj) + dist(nj,j);

            // cout << ans1 << " " << ans2 << " " << ans3 << " " << ans4 << endl;

            ans = min(ans,ans1);
            ans = min(ans,ans2);
            ans = min(ans,ans3);
            ans = min(ans,ans4);
        }

        if(ans > 2 * n) ans = -1;

        cout << ans << endl;
    }
}




int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}