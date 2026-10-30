#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<long long>;
using tiii = tuple<int,int,int>;
using vii = vector<vector<int>>;
using ld = long double;
#define all(v) ((v).begin()),((v).end())
#define sz(v) ((int)((v).size()))

ll memo[101][101];

ll nCr(int n, int m){
    if (m == 0) memo[n][m] = 1;
    if (m == n) memo[n][m] = 1;
    if(memo[n][m] != -1) return memo[n][m];
    memo[n][m] = (n* nCr(n-1,m-1))/m;
    return memo[n][m];
}


void solve(int n,int m){
    printf("%d things taken %d at a time is %lld exactly.\n", n, m, nCr(n,m));
    
}


int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    memset(memo,-1,sizeof(memo));

    int n,m;
    while(cin >> n >> m){
        if(n == m && n == 0){
            break;
        }
        solve(n,m);
    }
    
    return 0;
}
//then you will find joy in the LORD
//I will cause you to ride in triumph on
//the heights of the land
//and to feast on the inheritance of your father Jacob
