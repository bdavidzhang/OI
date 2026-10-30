#include<bits/stdc++.h>
using namespace std;

#define vi vector<int>
struct UF {
    vector<int> p, sz;
    UF(int n) : p(n), sz(n, 1) {
        iota(p.begin(), p.end(), 0);
    }
    int find(int x) {
        return p[x] == x ? x : p[x] = find(p[x]);
    }
    void unite(int a, int b) {
        a = find(a);
        b = find(b);
        if (a == b) return;
        p[a] = b;
        sz[b] += sz[a];
    }
};
int main(){
        int N, Q;
    cin >> N >> Q;
    UF dsu(N + 2);  
    vector<int> cnt(N + 2, 1); 

    while (Q--) {
        int X, Y;
        cin >> X >> Y;
        int rootY = dsu.find(Y);
        int before = cnt[rootY];
        while (true) {
            int fx = dsu.find(X);
            if (fx <= 0) break;
            if (fx > X) break;
            if (fx == rootY) break;
            cnt[rootY] += cnt[fx];
            cnt[fx] = 0;
            dsu.unite(fx, rootY);
            dsu.p[fx] = dsu.find(fx - 1);
            X = fx - 1;
        }
        cout << cnt[rootY] - before << "\n";
    }



}