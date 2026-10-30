#include <bits/stdc++.h>
using namespace std;

const int N = 1000000;   // number of nodes
const int M = 5000000;   // number of edges

// CSR graph storage
int head[N+5];     // start index of edges for each node
int deg[N+5];      // degree of each node
int to[M*2+5];     // destinations
int edgeStart[N+5]; // cumulative prefix sums

// Step 1: count degrees
void countDegrees(vector<pair<int,int>>& edges) {
    fill(deg, deg+N+1, 0);
    for (auto &e : edges) {
        deg[e.first]++;
    }
}

// Step 2: build CSR
void buildCSR(vector<pair<int,int>>& edges) {
    edgeStart[1] = 0;
    for (int i=1; i<=N; i++) {
        edgeStart[i+1] = edgeStart[i] + deg[i];
        head[i] = edgeStart[i]; // pointer to current insert pos
    }
    for (auto &e : edges) {
        int u = e.first, v = e.second;
        to[ head[u]++ ] = v;  // fill contiguous slot
    }
    // restore head[u] to beginning of its adjacency
    for (int i=1; i<=N; i++) {
        head[i] = edgeStart[i];
    }
}

// BFS with CSR
void bfs_csr(int start) {
    vector<char> vis(N+1, false);
    queue<int> q;
    q.push(start);
    vis[start] = true;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int i = edgeStart[u]; i < edgeStart[u+1]; i++) {
            int v = to[i];
            if (!vis[v]) {
                vis[v] = true;
                q.push(v);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // generate random graph
    mt19937 rng(12345);
    uniform_int_distribution<int> dist(1, N);
    vector<pair<int,int>> edges;
    edges.reserve(M);
    for (int i=0; i<M; i++) {
        int u = dist(rng), v = dist(rng);
        edges.push_back({u,v});
    }

    // build CSR
    countDegrees(edges);
    buildCSR(edges);

    auto t1 = chrono::high_resolution_clock::now();
    bfs_csr(1);
    auto t2 = chrono::high_resolution_clock::now();

    cout << "CSR BFS: " 
         << chrono::duration<double>(t2-t1).count() << "s\n";
}
