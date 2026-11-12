#include<bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())


signed main() {
    string s;
    cin >> s;
    auto idx = [&](char c) -> int { return (int)(c - 'A');};
    int n = sz(s);
    
    vector<vector<int>> adj(26);
    int cnt = 0;
    vector<bool> seen(n);
    for(int i = 0 ; i < n; ++i){
        if(!seen[idx(s[i])]) seen[idx(s[i])] = true, cnt++;
    }
    // cout << cnt << endl;
    if(cnt == 1){
        cout << s[0] << endl;
        return 0;
    }
    
    for(int i = 0; i < n - 1; ++i){
        int u = idx(s[i]), v = idx(s[i+1]);
        if(u != v){
        adj[u].push_back(v);
        adj[v].push_back(u);
        }
    }

    for(int i = 0; i <= 25; ++i){
        adj[i].erase(unique(all(adj[i])),adj[i].end());
        // cout << sz(adj[i]) << endl;
        if(sz(adj[i]) == 1) cout << (char)(i + 'A');  
    }
    cout << '\n';

    return 0;
}