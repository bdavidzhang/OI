#include<bits/stdc++.h>
using namespace std;

const int maxn = 510;
const int maxs = 310;
int s[maxn],t[maxn];
vector<int> g[maxn];
unordered_map<int,int> memo;

inline int comp(int v, int i, int b, int used){
    return ((v*maxn+i)*maxs+b)*2+used;
}

int solve(int v, int p, int i, int b, int used){
    if(i >= g[v].size()) return 0;
    int w = g[v][i];
    if(w == p) return solve(v,p,i+1,b,used);
    int x = comp(v,i,b,used);
    if(memo.find(x) == memo.end()){
        int y = 0;
        for(int bb = 0; bb <= b; ++bb){
            int next = solve(v,p,i+1,b-bb,used);
            y = max(y,solve(w,v,0,bb,0)+next);
            if(!used && s[w] <= bb) y = max(y,solve(w,v,0,bb-s[w],1)+next+t[w]);
        }
        memo[x] = y;
    }
    return memo[x];
}

int main(){
    int N,S;
    cin >> N >> S;
    for(int i = 1; i <= N; ++i) cin >> s[i] >> t[i];

    for(int i = 0; i < N-1; ++i){
        int u,v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    g[0].push_back(1);
    g[1].push_back(0);

    // for(int i = 0 ;i <= N; ++i){
    //     cout << s[i] << " ";
    // }
    // for(int i = 0; i <= N; ++i){
    //     for(auto &x : g[i]){
    //         cout << x <<" ";
    //     }
    //     cout << endl;
    // }

    cout << solve(0,-1,0,S,0) << endl;

    return 0;
}