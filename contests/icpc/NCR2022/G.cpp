//restaruant opening
#include<bits/stdc++.h>
using namespace std;

//can take O(n^4) algo, tho ugly

const int maxn = 55;
int grid[maxn][maxn];


int main(){

    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int n,m;
    cin >> n >> m;
    
    for(int i = 0; i < n; ++i){
        for(int j = 0;j < m; ++j){
            cin >> grid[i][j];
        }
    }


    long long ans = 1e9+10;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
           //simulate all coords (i,j) 
           long long cur = 0;
           for(int x = 0; x < n; ++x){
                for(int y = 0; y < m; ++y){
                    cur += grid[x][y] * (abs(i-x) + abs(j-y));         
                }
            } 
            ans = min(ans,cur);
        }
    }


    cout << ans << endl;




}