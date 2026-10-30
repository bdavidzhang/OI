//meeting - LUOGU
//solution using centroids
#include<bits/stdc++.h>

using namespace std;

const int MAXN = 5e4+10;


vector<int> subtree_size(MAXN);
vector<list<int>> adj(MAXN);
int n;

int get_subtree_size(int node, int parent = -1){
    int &res = subtree_size[node];
    res = 1;
    for(int x : adj[node]){
        if(x == parent) continue;
        res += get_subtree_size(x,node); 
    }
    return res;
}

int get_centroid(int node, int parent = -1){
    for (int x: adj[node]){
        if(x == parent) continue;
        if(subtree_size[x] * 2 > n) return get_centroid(x, node);
    }
    return node;
    
}

void DFSutil(int node, vector<bool> &vs, vector<int> &dist, int d, stack<int> &s){
    if(vs[node]) return ;
    vs[node] = true;
    dist[node] = d;

    s.push(node);
    //cout << node << endl;
    while(!s.empty()){
        int k = s.top();
        s.pop();      
        for(int x : adj[k]){
            DFSutil(x, vs, dist, d+1, s);
        }
    }
}

int DFS(int cent){
    vector<bool> vs(MAXN);
    vector<int> dist(MAXN);

    stack<int> s;
    DFSutil(cent, vs, dist, 0, s);
    
    long long sum= 0;

    for(int i = 1; i <= n; ++i){
        sum += dist[i]; 
    }
    return sum;
}

void BFSutil(int cent, vector<bool> &vs, vector<int> &dist, int d, queue<int> q){
    if(vs[cent]) return;
    vs[cent] = true; 

    q.push(cent);
    dist[cent] = d;
    while(!q.empty()){
        int cur = q.front(); 
        q.pop();
        for(int x : adj[cur]){
            if(!vs[x]){
                BFSutil(x,vs,dist,d+1,q); 
            } 
        }
    } 
}



int BFS(int cent){
    vector<bool> vs(MAXN);
    vector<int> dist(MAXN);

    queue<int> q;
    BFSutil(cent, vs, dist, 0, q);
    
    long long sum= 0;

    for(int i = 1; i <= n; ++i){
        sum += dist[i]; 
    }
    return sum;
}

int main(){
    cin >> n;
    for(int i = 0; i < n-1; ++i){
        int a,b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    get_subtree_size(1);
    int cent = get_centroid(1);

    int val = BFS(cent);

    cout << cent << " " << val << endl;


    return 0;
}
