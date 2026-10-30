#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)9e18;

ll gcd(ll a, ll b){ while(b){ a%=b; swap(a,b);} return a; }
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--){
        int n; ll m;
        cin >> n >> m;
        vector<int> a(n), b(n);
        for(int i=0;i<n;++i) cin >> a[i];
        for(int i=0;i<n;++i) cin >> b[i];

        int L = 1;
        for(int x : a){
            int g = (int)gcd(L, x);
            L = L / g * x;
        }

        int fullmask = (1<<n) - 1;
        vector<int> forb(L, 0);
        for(int s=0; s<L; ++s){
            int mask = 0;
            for(int i=0;i<n;++i){
                if (s % a[i] == b[i]) mask |= (1<<i); 
            }
            forb[s] = mask;
        }

        bool impossible = false;
        for(int s=0; s<L; ++s){
            if(forb[s] == fullmask){
                ll firstPos = (s == 0) ? L : s;
                if (firstPos <= m) { impossible = true; break; }
            }
        }
        if(impossible){
            cout << -1 << '\n';
            continue;
        }

        if (m <= (ll)L){
            int curPhase = 0; 
            ll totalTime = 0;
            bool ok = true;
            for(ll i = 1; i <= m; ++i){
                int s = (int)(i % L);
                bool found = false;
                for(int d = 1; d <= n; ++d){
                    int r = (curPhase + d - 1) % n;
                    if ((forb[s] >> r & 1) == 0){
                        totalTime += d;
                        curPhase = (curPhase + d) % n;
                        found = true;
                        break;
                    }
                }
                if(!found){ ok = false; break; }
            }
            cout << (ok ? totalTime : -1) << '\n';
            continue;
        }

        vector<ll> cost(n, INF);
        vector<int> endPhase(n, -1);

        for(int p = 0; p < n; ++p){
            int curPhase = p;
            ll tot = 0;
            bool ok = true;
            for(int idx = 1; idx <= L; ++idx){
                int s = idx % L;
                bool found = false;
                for(int d = 1; d <= n; ++d){
                    int r = (curPhase + d - 1) % n;
                    if (((forb[s] >> r) & 1) == 0){
                        tot += d;
                        curPhase = (curPhase + d) % n;
                        found = true;
                        break;
                    }
                }
                if(!found){ ok = false; break; }
                if(tot > INF/4){ ok = false; break; } 
            }
            if(ok){ cost[p] = tot; endPhase[p] = curPhase; }
            else { cost[p] = INF; endPhase[p] = -1; }
        }


        ll q = m / L;
        int MAXB = 0;
        while((1LL<<MAXB) <= q) ++MAXB;
        vector<vector<int>> up(MAXB, vector<int>(n, -1));
        vector<vector<ll>> csum(MAXB, vector<ll>(n, INF));
        for(int p=0;p<n;++p){
            up[0][p] = endPhase[p]; 
            csum[0][p] = cost[p];
        }
        for(int k=1;k<MAXB;++k){
            for(int p=0;p<n;++p){
                int mid = up[k-1][p];
                if(mid == -1){ up[k][p] = -1; csum[k][p] = INF; continue; }
                int to = up[k-1][mid];
                if(to == -1){ up[k][p] = -1; csum[k][p] = INF; continue; }
                up[k][p] = to;
                if (csum[k-1][p] >= INF || csum[k-1][mid] >= INF) csum[k][p] = INF;
                else {
                    csum[k][p] = csum[k-1][p] + csum[k-1][mid];
                    if(csum[k][p] > INF) csum[k][p] = INF;
                }
            }
        }

        int curPhase = 0;
        ll totalTime = 0;
        bool okBlocks = true;
        for(int k=0; k<MAXB; ++k){
            if((q>>k) & 1LL){
                if(up[k][curPhase] == -1 || csum[k][curPhase] >= INF){ okBlocks = false; break; }
                totalTime += csum[k][curPhase];
                curPhase = up[k][curPhase];
            }
        }
        if(!okBlocks){
            cout << -1 << '\n';
            continue;
        }

        int r = (int)(m % L);
        bool ok = true;
        for(int i = 1; i <= r; ++i){
            int s = i % L; 
            bool found = false;
            for(int d = 1; d <= n; ++d){
                int rr = (curPhase + d - 1) % n;
                if(((forb[s] >> rr) & 1) == 0){
                    totalTime += d;
                    curPhase = (curPhase + d) % n;
                    found = true;
                    break;
                }
            }
            if(!found){ ok = false; break; }
        }
        if(!ok) cout << -1 << '\n';
        else cout << totalTime << '\n';
    }
    return 0;
}
