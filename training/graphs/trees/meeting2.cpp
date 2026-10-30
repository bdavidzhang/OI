//meeting - LUOGU - using DFS + child trees 
#include<bits/stdc++.h>
using namespace std;

const int MAXN = 5e4+10;

vector<vector<int>> g(MAXN);
vector<int> dist(MAXN);
stack<int> s;
vector<bool> vs(MAXN);
vector<int> totdist(MAXN);
vector<int> stsz(MAXN);


void DFS(int node,int d){
    if(vs[node]) return;
    vs[node] = true;
    dist[node] = d;
    s.push(node); 

    while(!s.empty()){
        int cur = s.top();
        s.pop();
        for(int x : g[cur]){
            if(!vs[x]){
                DFS(x,d+1); 
            } 
        } 
         
    }
   
}

int getstsz(int node, int par = -1){
    int &res = stsz[node];    
    res = 1;
    for (int x : g[node]){
        if(x == par) continue;
        res += getstsz(x, node); 
    }
    return res;
}

void solve(int n,int node = 1, int par = -1){
    for(int x : g[node]){
        if( x == par) continue;
        totdist[x] = totdist[node] - stsz[x] + (n - stsz[x]);
        solve(n,x, node);
    }
}


int main(){
    int n;
    cin >>n;
    for(int i = 0; i < n-1; ++i){
        int a,b;
        cin >> a  >>b; 
        g[a].push_back(b);
        g[b].push_back(a);
    }
    DFS(1,0); 
    for(int i = 1; i <= n; ++i){
        totdist[1] += dist[i]; 
    }
    getstsz(1);
    solve(n); 
    int mini = totdist[1];
    int idx = 1;
   for(int i = 1; i<=n; ++i){
       //cout << totdist[i] << endl;
       if(mini > totdist[i]){
            mini = totdist[i];
            idx = i;
       }

   } 

    cout << idx << " " << mini << endl;


}

