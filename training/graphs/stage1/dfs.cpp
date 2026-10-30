#include<bits/stdc++.h>
using namespace std;

void addEdge(vector<vector<int>> &adj, int s, int t){

    adj[s].push_back(t);
    adj[t].push_back(s);
}

void DFSRec(vector<vector<int>> &adj, vector<bool> &visited, int s){
    if(visited[s] == true) return;
    visited[s] = true;
    
    cout<< s << " ";

    for(int t :adj[s]){
        DFSRec(adj, visited, t); 
    }
}

void DFSpoint(vector<vector<int>> &adj, int s){
    vector<bool> visited(adj.size(), false); 
    DFSRec(adj, visited, s);
}

void DFSall(vector<vector<int>> &adj){
    vector<bool> visited(adj.size());            
    for(int i = 0;i < adj.size(); ++i){
        DFSRec(adj,visited,i);
    }    
}

int main(){

    int V = 6;
    vector<vector<int>> adj(V);
    
    vector<vector<int>> edges = {{0,1}, {1,2}, {2,4}, {4,5}};

    for(auto x : edges){
        addEdge(adj, x[0], x[1]);
    }

    DFSpoint(adj, 0);

}
