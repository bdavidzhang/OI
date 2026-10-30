// Including necessary header file
#include <bits/stdc++.h>
using namespace std;



vector<int> topo(int V, vector<vector<int> >& adj)
{
    vector<int> id(V), result, empty;
    queue<int> q;
    for(int i = 0; i < V; ++i)
        for(auto it: adj[i])
            id[it]++;
    
    for(int i = 0; i < V; ++i)
        if(id[i] == 0) q.push(i);
    
    while(!q.empty()){
        int cur = q.front();q.pop();
        result.push_back(cur);
        for(auto it: adj[cur])
            if(--id[it] == 0) q.push(it);
    }
    
    if(result.size() != V) return empty;
    return result;
}

int main()
{
    int n,m;
    cin >> n >> m;
    vector<vector<int>> adj(n);

    for(int i = 0; i < m; ++i){
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
    }


    auto result = topo(n,adj);
    // Displaying result
    for (auto i : result) {
        cout << i+1 << " ";
    }
    cout << endl;

    return 0;
}