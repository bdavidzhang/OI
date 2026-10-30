#include<bits/stdc++.h>
using namespace std;

using vi = vector<int>;
using vb = vector<bool>;
#define pb push_back

void addEdge(vector<vi> &adj, int s, int t){
    adj[s].pb(t);
    adj[t].pb(s);
}

void BFS(vector<vi> &adj, vb visited, int s){
    queue<int> q;
    if(visited[s] == true) return;

    visited[s] = true;
    q.push(s);

    while(!q.empty()){
        int curr = q.front(); 
        q.pop(); 
        cout<<curr << " " ;

        //get all adj vertices of curr
        for (int x : adj[curr]){
            if(!visited[x]){
                visited[x] = true;//mark as visited
                q.push(x); //enque
            } 
        }
    }
}

void BFSDisconnected(vector<vi> &adj){
    vb visited(adj.size(),false);
    for(int i = 0; i < adj.size(); ++i){
        if(!visited[i]){
            BFS(adj, visited, i); 
        } 
    }
}

int main() 
{
    // Number of vertices in the graph
    int V = 5;

    // Adjacency list representation of the graph
    vector<vector<int>> adj(V);

    // Add edges to the graph
    addEdge(adj, 0, 4);
    addEdge(adj, 0, 3);
    addEdge(adj, 1, 3);
    addEdge(adj, 1, 4);
    addEdge(adj, 2, 4);

    // Mark all the vertices as not visited
    vector<bool> visited(V, false);

    // Perform BFS traversal starting from vertex 0
    cout << "BFS starting from 0 : \n";
    BFS(adj, visited, 0);

    return 0;
}
