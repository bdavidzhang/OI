//finding a centroid
//by definition, a centroid is a node for which all subtries have size <= N/2, where N is the number
//of nodes
#include<bits/stdc++.h>
using namespace std;


int get_subtree_size(int node, vector<int> &subtree_size, vector<list<int>> &adj, int parent = -1){
    int &res = subtree_size[node];
    res = 1;
    for(int x : adj[node]){
        if(x == parent) continue;
        res += get_subtree_size(x,subtree_size,adj,node); 
    }
    return res;
}

int get_centroid(int node, vector<int> &subtree_size, vector<list<int>> &adj, int n, int parent = -1){
    for(int x : adj[node]){
        if(x == parent) continue;
        if(subtree_size[x] * 2 > n) return get_centroid(x,subtree_size, adj, n, node);
    }
    return node;
}





int main(){

    int n;
    cin >> n;
    vector<list<int>> adj(n+1);
    for(int i = 0;i < n-1; ++i){
        int a,b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    vector<int> subtree_size(n+1);

    get_subtree_size(1,subtree_size,adj);
    int cent = get_centroid(1,subtree_size,adj,n);

    cout << cent << endl; 

    return 0;
}
