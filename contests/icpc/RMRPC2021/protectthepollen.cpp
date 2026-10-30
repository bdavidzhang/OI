#include<bits/stdc++.h>
using namespace std;

const int MAXN = 510, MAXS = 310;
int s[MAXN], t[MAXN];
vector<int> g[MAXN];

unordered_map<int,int> memo;

int comp(int v, int i, int b, bool used){
    return ((v*MAXN+i)*MAXS+b)*2 + used;
}

int solve(int v, int p, int i, int b, bool used){
    if(i >= g[v].size()) return 0;
    int w = g[v][i];
    if(w == p) return solve(v,p,i+1,b,used);
    int x = comp(v,i,b,used);
    if(memo.find(x) == memo.end()){
        int y = 0;
        for(int bb = 0; bb <= b; ++bb){
            int next = solve(v,p,i+1,b-bb,used);
            y = max(y,next+solve(w,v,0,bb,0));
            if(!used && s[w] <= bb) y = max(y,next+t[w]+solve(w,v,0,bb-s[w],1));
        }
        memo[x] = y;
    }
    return memo[x];
}


int main(){
    int n, S;
    cin >> n >> S;

    for(int i = 1; i <= n; ++i){
        cin >> s[i] >> t[i];
    }
    for(int i =0 ;i < n-1; ++i){
        int u,v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    g[0].push_back(1);
    g[1].push_back(0);

    cout << solve(0,-1,0,S,0) << endl;    


    return 0;
}