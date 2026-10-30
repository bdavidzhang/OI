#include <bits/stdc++.h>
using namespace std;

const int N = 1000000;   // number of nodes
const int M = 5000000;   // number of edges

// ====== Forward star ======
int head[N+5], to[M*2+5], nxt[M*2+5], idx;
void addEdge(int u, int v) {
    to[idx] = v;
    nxt[idx] = head[u];
    head[u] = idx++;
}

// BFS with forward star
void bfs_forward(int start) {
    vector<bool> vis(N+1, false);
    queue<int> q;
    q.push(start); vis[start]=true;
    while(!q.empty()) {
        int u = q.front(); q.pop();
        for(int i = head[u]; i != -1; i = nxt[i]) {
            int v = to[i];
            if(!vis[v]) {
                vis[v] = true;
                q.push(v);
            }
        }
    }
}

// ====== Adjacency list ======
vector<int> adj[N+5];

// BFS with adjacency list
void bfs_adj(int start) {
    vector<bool> vis(N+1, false);
    queue<int> q;
    q.push(start); vis[start]=true;
    while(!q.empty()) {
        int u = q.front(); q.pop();
        for(int v : adj[u]) {
            if(!vis[v]) {
                vis[v] = true;
                q.push(v);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // init head for forward star
    fill(head, head+N+1, -1);
    idx = 0;

    // build random graph
    mt19937 rng(12345);
    uniform_int_distribution<int> dist(1,N);

    for (int i=0; i<M; i++) {
        int u = dist(rng), v = dist(rng);
        addEdge(u, v);
        adj[u].push_back(v);
    }

    auto t1 = chrono::high_resolution_clock::now();
    bfs_forward(1);
    auto t2 = chrono::high_resolution_clock::now();
    bfs_adj(1);
    auto t3 = chrono::high_resolution_clock::now();

    cout << "Forward star BFS: " 
         << chrono::duration<double>(t2-t1).count() << "s\n";
    cout << "Adjacency list BFS: "
         << chrono::duration<double>(t3-t2).count() << "s\n";
}
