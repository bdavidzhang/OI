#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<long long>;
using tiii = tuple<int,int,int>;
using vii = vector<vector<int>>;
#define all(v) ((v).begin()),((v).end())
#define sz(v) ((int)((v).size()))

int max(int a, int b, int c){
    return max(max(a,b),c);
}



void solve(){
   int n;
   cin >> n;
   vi g(n+1), c(n+1), no(n+1);
   for(int i = 1; i <= n; ++i){
       int x;
       cin >> x;
       if(x == 0){
        no[i] = max(g[i-1],c[i-1],no[i-1]);
       }
       else if( x==1){
        c[i] = max(no[i-1],g[i-1])+1;
        no[i] = max(c[i-1],g[i-1],no[i-1]); 
       }
       else if(x == 2){
        g[i] = max(no[i-1],c[i-1])+1;
        no[i] = max(c[i-1],g[i-1],no[i-1]); 
       }
       else{
        c[i] = max(no[i-1],g[i-1])+1;
        g[i] = max(no[i-1],c[i-1])+1;
        no[i] = max(c[i-1],g[i-1],no[i-1]); 
       }
   }

   cout << n-max(c[n],g[n],no[n]) << endl;
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
