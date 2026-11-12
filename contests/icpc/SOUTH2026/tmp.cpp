#include<bits/stdc++.h>

#include <cassert>
using namespace std;
#define int long long
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
#define rep(i,a,b) for( int i = (a) , i##end = (b) ; i <= i##end ; ++ i )
int n,m;
const int MAXN = 5e5 + 20;

int lp[28] , pst[28];
int cur[28] , lst = 1;
int son[MAXN][2] , le[MAXN][2] , fa[MAXN] , vv[MAXN] , idx = 1;
void ins( int c , int val = 1 ) {
    le[idx][0] = c;
    son[idx][0] = idx + 1;
    ++ idx;
    fa[idx] = idx - 1;
    vv[idx] = val;
}
int wf( int x ) {
    return son[fa[x]][1] == x;
}
int st;
void fork( int par , int cur , int len ) {
    if( cur != par ) fork( par , fa[cur] , len );
    if( fa[cur] == par ) {
        cur = fa[cur];
        assert( !son[cur][1] );
        ++ idx;
        son[cur][1] = idx;
        le[cur][1] = len;
        fa[idx] = cur;
        vv[idx] = 0;
        cout << "FORKED " << cur << ' ' << idx << ' ' << endl;
        return;
    }
    int br = wf( cur );
    le[idx][0] = le[cur][br];
    cout << cur << ' ' << par << " CHANGED " << idx << " towards next " << endl;
    son[idx][0] = idx + 1;
    ++ idx;
    vv[idx] = 0;
    fa[idx] = idx - 1;
}

const int P = 998244353;
int qm( int x ) {
    return x < P ? x : x - P;
}

int Pow( int x , int a ) {
    int ret = 1;
    while( a ) {
        if( a & 1 ) ret = ret * 1ll * x % P;
        x = x * 1ll * x % P; a >>= 1;
    }
    return ret;
}

struct SAM {
    static const int MAXN = 300005 * 2;
    map<int,int> son[MAXN];
    int par[MAXN] , len[MAXN];
    int lst , cnt;
    int res[MAXN];
    void init() {
        lst = cnt = 1;
    }
    void ins( int x , int v ) {
        cout << x << ' ' << lst << ' ' << v << endl;
        int cur = ++ cnt;
        res[cur] += v;
        len[cur] = len[lst] + 1;
        int p = lst;
        while( p && !son[p].count( x ) ) son[p][x] = cur , p = par[p];
        if( !p ) par[cur] = 1;
        else {
            int q = son[p][x];
            if( len[q] == len[p] + 1 ) par[cur] = q;
            else {
                int ct = ++ cnt;
                len[ct] = len[p] + 1 , par[ct] = par[q];
                son[ct] = son[q];
                par[q] = par[cur] = ct;
                for( ; son[p][x] == q ; p = par[p] ) son[p][x] = ct;
            }
        }
        lst = cnt;
    }
    int gans( ) {
        int ans = 0;
        rep( i , 2 , cnt ) {
            cout << "NODE " << i << ' ' << len[i] << ' ' << par[i] << endl;
            if( res[i] ) ans += len[i] - len[par[i]];
        }
        return ans;
    }
    void printdag( int u ) {
        for( const auto&[ c , v ] : son[u] ) {
            cout << " edge " << u << " -> " << v << " weighted " << c << endl;
        }
        for( const auto&[ c , v ] : son[u] ) {
            printdag( v );
        }
    }
    int dp[MAXN][27] , vis[MAXN] , J[28] , iJ[29];
    int solveit( ) {
        dp[1][0] = 1;
        queue<int> Q;
        Q.push( 1 );
        while( Q.size() ) {
            int u = Q.front(); Q.pop();
            
        for( auto& [c , v] : son[u] ) {
            if( !c ) {
                rep( k , 1 , 26 ) dp[v][k] = qm( dp[v][k] + dp[u][k - 1] );
            } else {
                rep( k , 0 , 26 ) dp[v][k] = qm( dp[v][k] + dp[u][k] );
            }
            if( !vis[v] ) vis[v] = 1 , Q.push( v );
        }


        }
        J[0] = 1;
        rep( i , 1 , 26 ) J[i] = J[i - 1] * i % P , iJ[i] = Pow( J[i] , P - 2 );
        int ans = 0;
        rep( i , 2 , cnt ) {
            rep( k , 0 , 26 ) {
                ans = ( ans + dp[i][k] * 1ll * J[26] % P * iJ[26 - k] ) % P;
                if( dp[i][k] )
                    cout << i << ' ' << k << ' ' << dp[i][k] << ' ' << ans << endl;
            }
        }
        return ans;
    }
} S ;

int dx[MAXN];
void bfs( int s ) {
    queue<int> Q;
    Q.push( s );
    dx[s] = 1;
    while( Q.size() ) {
        int u = Q.front(); Q.pop();
        cout << "SONS " << u << ' ' << son[u][0] << ' ' << son[u][1] << endl;
        rep( i , 0 , 1 ) if( son[u][i] ) {
            S.lst = dx[u];
            int v = son[u][i];
            S.ins( le[u][i] , vv[v] );
            dx[v] = S.lst;
            Q.push( v );
        cout << "INSERTED " << le[u][i] << " from " << dx[u] << endl;
        S.printdag( 1 );
        cout << " ------ " << endl;
        }
    }
}


void solve() {
    S.init();
    string SS;
    cin >> SS;
    n = SS.length();
    memset( lp , -1 , sizeof lp );
    for( int i = 0 ; i < n ; ++ i ) {
        cout << i << endl;
        int c = SS[i] - 'a';
        cout << i << ' ' << idx << ' ' << pst[c] << " SON 3 " << son[3][0] << endl;
        if( lp[c] != -1 ) {
            fork( pst[c] , idx , i - lp[c] );
        }
        cout << i << ' ' << idx << ' ' << pst[c] << " SON 3 " << son[3][0] << endl;
        pst[c] = idx;
        ins( 0 );
        lp[c] = i;
    }
    bfs( 1 );
    cout << S.gans( ) << endl;
    cout << S.solveit( ) << endl;

}

signed main() {
    srand( ( long long ) new char );
    int T = 1;
    // cin >> T;
    while( T-- ) solve();
}

/*

galoiz@zem:~/code/OI/contests/icpc/SOUTH2026$ g++ tmp.cpp -o tmp && ./tmp < .in
0
1
2
4 0 0 ---- 
FORKED 1 5 
6 0 0 ---- 
SONS 1 2 5
0 1 1
INSERTED 0 from 1
 edge 1 -> 2 weighted 0
 ------ 
2 1 0
INSERTED 2 from 1
 edge 1 -> 2 weighted 0
 edge 1 -> 3 weighted 2
 ------ 
SONS 2 3 0
0 2 1
INSERTED 0 from 2
 edge 1 -> 2 weighted 0
 edge 1 -> 3 weighted 2
 edge 2 -> 4 weighted 0
 ------ 
SONS 5 6 0
0 3 0
INSERTED 0 from 3
 edge 1 -> 2 weighted 0
 edge 1 -> 3 weighted 2
 edge 2 -> 4 weighted 0
 edge 3 -> 5 weighted 0
 ------ 
SONS 3 4 0
0 4 0
INSERTED 0 from 4
 edge 1 -> 2 weighted 0
 edge 1 -> 3 weighted 2
 edge 2 -> 4 weighted 0
 edge 4 -> 6 weighted 0
 edge 3 -> 5 weighted 0
 ------ 
SONS 6 7 0
0 5 1
INSERTED 0 from 5
 edge 1 -> 2 weighted 0
 edge 1 -> 3 weighted 2
 edge 2 -> 4 weighted 0
 edge 4 -> 6 weighted 0
 edge 3 -> 5 weighted 0
 edge 5 -> 7 weighted 0
 ------ 
SONS 4 0 0
SONS 7 0 0
NODE 2 1 1
NODE 3 1 1
NODE 4 2 2
NODE 5 2 2
NODE 6 3 4
NODE 7 3 4
3
2 1 1 26
3 0 1 27
4 2 1 677
5 1 1 703
6 3 1 16303
7 2 1 16953
16953
*/