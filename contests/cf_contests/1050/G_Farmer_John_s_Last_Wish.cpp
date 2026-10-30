#include <bits/stdc++.h>
using namespace std;

const int N = 200005;
int spf[N], cnt[N], seg[4*N];
vector<int> divs;

void sieve() {
    for (int i = 1; i < N; i++) spf[i] = i;
    for (int i = 2; i * i < N; i++) if (spf[i] == i)
        for (int j = i * i; j < N; j += i) if (spf[j] == j) spf[j] = i;
}

void rec(int idx, int cur, vector<pair<int,int>>& f) {
    if (idx == (int)f.size()) { divs.push_back(cur); return; }
    int p = f[idx].first, a = f[idx].second, t = 1;
    for (int i = 0; i <= a; i++) {
        rec(idx+1, cur*t, f);
        t *= p;
    }
}

void get_divs(int x) {
    divs.clear();
    if (x == 1) { divs.push_back(1); return; }
    map<int,int> mp;
    while (x > 1) { mp[spf[x]]++; x /= spf[x]; }
    vector<pair<int,int>> f(mp.begin(), mp.end());
    rec(0,1,f);
}

void upd(int v, int l, int r, int i, int val) {
    if (l == r) { seg[v] = val; return; }
    int m = (l+r)/2;
    if (i <= m) upd(v*2,l,m,i,val);
    else upd(v*2+1,m+1,r,i,val);
    seg[v] = max(seg[v*2], seg[v*2+1]);
}

int qry(int v, int l, int r, int L, int R) {
    if (R < l || r < L) return 0;
    if (L <= l && r <= R) return seg[v];
    int m = (l+r)/2;
    return max(qry(v*2,l,m,L,R), qry(v*2+1,m+1,r,L,R));
}

int gcd2(int a,int b){ return b ? gcd2(b,a%b) : a; }

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (int &x:a) cin >> x;
    fill(cnt,cnt+n+1,0);
    fill(seg,seg+4*(n+1),0);
    int g = 0;
    for (int i=0;i<n;i++) {
        g = i?gcd2(g,a[i]):a[i];
        get_divs(a[i]);
        for (int d:divs) {
            cnt[d]++;
            upd(1,1,n,d,cnt[d]);
        }
        int ans = (g>=n?0:qry(1,1,n,g+1,n));
        cout<<ans<<" ";
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    sieve();
    int t; cin >> t;
    while (t--) solve();
}
