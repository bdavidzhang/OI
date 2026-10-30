#include<bits/stdc++.h>
using namespace std;

const int MAXN = 510;
const int MAXS = 1010;

int s[MAXN], t[MAXN];
vector<int> g[MAXN];

unordered_map<int, int> memo;



//this is a mixed radix way to get a hash
//v is the current vertex, i is the child vertex 
//b is the personel budget, used is a boolean variable
//i < MAXN, b < MAXS, used < 2
//so you can use this for compress state dp
inline int comp(int v, int i, int b, int used){
    return ((v*MAXN + i) * MAXS + b)*2 + used;
}



int solve(int v, int p, int i, int b, int used){//i:index of child
    if(i >= g[v].size()) return 0; //invalid child

    int w = g[v][i]; //current node
    if (w==p) return solve(v,p,i+1,b,used); //w is not parent

    int x = comp(v,i,b,used); // hash value for cur state
    if (memo.find(x) == memo.end()){
        int y = 0;

        for(int bb = 0; bb <= b; ++bb){//bb:available budget
            int next = solve(v, p, i+1, b-bb, used);//gets best result from sibling
            //DON't use family w
            y = max(y, solve(w,v,0,bb,0) + next);
            //USE family w if possible
            if (used == 0 && s[w] <= bb) y = max(y, solve(w,v,0,bb-s[w],1) + t[w] + next);
        }
        memo[x] = y;
    }
    return memo[x];
}


int main(){
    int n,S;
    cin >> n >>S;
    for(int i = 1; i <= n; ++i) cin >> s[i] >> t[i];
    for(int i = 0, u, v; i < n - 1; ++i){
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    g[0].push_back(1);
    g[1].push_back(0);

    cout << solve(0,-1,0,S,false) << endl;

    return 0;
}