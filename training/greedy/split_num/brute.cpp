#include <bits/stdc++.h>
using namespace std;

// compute height (max distance in edges) from root=1 with BFS
int height_from_root(const vector<vector<int>> &g, int root = 1) {
    int n = (int)g.size() - 1;
    vector<int> dist(n+1, -1);
    queue<int> q;
    dist[root] = 0;
    q.push(root);
    int best = 0;
    while(!q.empty()){
        int u = q.front(); q.pop();
        best = max(best, dist[u]);
        for(int v : g[u]){
            if(dist[v] == -1){
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
    return best;
}

// canonical encode of adjacency (node lists sorted) to a string
string encode_graph(const vector<vector<int>> &g) {
    int n = (int)g.size() - 1;
    string s;
    s.reserve(n * 10);
    for(int i = 1; i <= n; ++i){
        vector<int> tmp = g[i];
        sort(tmp.begin(), tmp.end());
        s.push_back('#');
        s += to_string(i);
        s.push_back(':');
        for(int j = 0; j < (int)tmp.size(); ++j){
            if(j) s.push_back(',');
            s += to_string(tmp[j]);
        }
    }
    return s;
}

// compute parent[] and depth[] when rooted at 1
void compute_parent_depth(const vector<vector<int>> &g, vector<int> &parent, vector<int> &depth, int root = 1) {
    int n = (int)g.size() - 1;
    parent.assign(n+1, 0);
    depth.assign(n+1, -1);
    queue<int> q;
    depth[root] = 0;
    parent[root] = 0;
    q.push(root);
    while(!q.empty()){
        int u = q.front(); q.pop();
        for(int v : g[u]){
            if(depth[v] == -1){
                depth[v] = depth[u] + 1;
                parent[v] = u;
                q.push(v);
            }
        }
    }
}

// remove undirected edge u-v from adjacency (assumes exists)
void remove_edge(vector<vector<int>> &g, int u, int v){
    auto it = find(g[u].begin(), g[u].end(), v);
    if(it != g[u].end()) g[u].erase(it);
    it = find(g[v].begin(), g[v].end(), u);
    if(it != g[v].end()) g[v].erase(it);
}

// add undirected edge u-v
void add_edge(vector<vector<int>> &g, int u, int v){
    g[u].push_back(v);
    g[v].push_back(u);
}

// brute-force search with memoization: returns minimal height achievable with up to k operations
int brute_min_height(vector<vector<int>> &g, int k, unordered_map<string,int> &memo, int root = 1) {
    string key = encode_graph(g) + "#" + to_string(k);
    auto it = memo.find(key);
    if(it != memo.end()) return it->second;

    int cur_h = height_from_root(g, root);
    int best = cur_h;
    if(k == 0){
        memo[key] = best;
        return best;
    }
    // trivial pruning: if best is already 0 or 1, can't do better than 0
    if(best <= 1){
        memo[key] = best;
        return best;
    }

    int n = (int)g.size() - 1;
    vector<int> parent, depth;
    compute_parent_depth(g, parent, depth, root);

    // consider every parent->child edge (child deeper than parent)
    for(int child = 1; child <= n; ++child){
        int p = parent[child];
        if(p == 0) continue;         // root or unreachable
        if(p == root) continue;     // cutting parent==root is redundant (child already direct under root)
        // perform the operation: cut (p, child), attach child under root
        vector<vector<int>> nxt = g;
        remove_edge(nxt, p, child);
        add_edge(nxt, root, child); // attach child to root
        int res = brute_min_height(nxt, k-1, memo, root);
        if(res < best) best = res;
        if(best == 0) break; // can't improve further
    }
    memo[key] = best;
    return best;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("brute_out.txt","w",stdout);
#endif

    int n, k;
    if(!(cin >> n >> k)) return 0;

    vector<vector<int>> g(n+1);
    for(int i = 0; i < n-1; ++i){
        int u,v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    // Safety guard: this brute is exponential; only use for small n.
    if(n > 12){
        cerr << "Warning: brute solver is intended for small n (<=12). Exiting.\n";
        // If you still want to run it, remove the exit and allow potentially long runtime.
        return 0;
    }

    unordered_map<string,int> memo;
    memo.reserve(100000);
    int ans = brute_min_height(g, k, memo, 1);
    cout << ans-1 << "\n";
    return 0;
}
