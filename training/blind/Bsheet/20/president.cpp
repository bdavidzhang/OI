#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<long long>;
using tiii = tuple<int,int,int>;
using vii = vector<vector<int>>;
#define all(v) ((v).begin()),((v).end())
#define sz(v) ((int)((v).size()))

int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};

bool isvalid(int i, int j, int m, int n){
    return i >= 0 && i < n && j >= 0 && j < m;   
}

void solve(){
   int n, m;
   char c;
   cin >>n  >> m >> c;
   vector<string> g(n);
   set<char> vis;
   for(int i = 0; i <n; ++i){
        cin >> g[i];
   }

   ll cnt = 0;
   for(int i = 0 ;i < n; ++i){
        for(int j = 0 ;j < m; ++j){
            if(g[i][j] == c){
               for(int k = 0 ;k <4;++k){
                   if(isvalid(i+dx[k],j+dy[k],m,n)){
                       char t = g[i+dx[k]][j+dy[k]];
                       if(t != c && isalpha(t) && !vis.contains(t)){
                           vis.insert(t);
                            cnt++;
                            }
               }
            }
        }
        }
   }
   cout << cnt << endl;
}


int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1e9+7; 
    //cin >> t;
    for(int i = 0; i < t; ++i){
        if(t == 1e9+7){
            solve();
            break;
        }
    }
    return 0;
}
//then you will find joy in the LORD
//I will cause you to ride in triumph on
//the heights of the land
//and to feast on the inheritance of your father Jacob
