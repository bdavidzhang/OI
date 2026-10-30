#include<bits/stdc++.h>
using namespace std;

const int N = 110;
bitset<N> ans;

int gauss (vector < bitset<N> > a,int n, int m) {
    int send = 1;
    vector<int> where(m,-1);
    for(int col = 0, row = 0; col < m && row < n; ++col){
        for(int i = row; i < n; ++i){
            if(a[i][col]){
                swap(a[i],a[row]);
                break;
            }
        }
        if(!a[row][col]) continue;
        where[col]=row;
        for(int i = 0;i < n; ++i){
            if(i !=row && a[i][col]) a[i] ^= a[row];
        }
        ++row;
    }
    for(int i = 0; i < m; ++i){
        if(where[i] != -1) ans[i] = a[where[i]][m];
        else send = 2;
    }
    for(int i = 0; i < n; ++i){
        int sum = 0;
        for(int j = 0; j < m; ++j){
            sum ^= (ans[j] * a[i][j]);
        }
        if(sum != a[i][m]) return 0;
    }
    return send;
}


int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int n,m;
    cin >> n >> m;
    vector<bitset<N>> a(n);
    for(int i = 0; i< m; ++i){
        int u,v;
        cin >> u >>v;
        u--;v--;
        a[u][v] = a[v][u] = 1;
    }

    for(int i = 0; i < n; ++i){
        int tot = a[i].count();
        a[i][i] = (tot & 1);
        a[i][n] = (tot & 1) ? 0 : 1;
    }

    // for(int i =0; i < n; ++i){
    //     for(int j = 0; j < N; ++j){
    //         cout << a[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    int res = gauss(a,n,n);
    if(res >= 1) cout << "Y" << endl;
    else cout <<"N" << endl;

    return 0;
}