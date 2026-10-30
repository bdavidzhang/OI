#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<long long>;
using tiii = tuple<int,int,int>;
using vii = vector<vector<int>>;
#define all(v) ((v).begin()),((v).end())
#define sz(v) ((int)((v).size()))


void solve(){
    int n;
    cin >> n;
    vi pos(n+1);
    for(int i = 1;  i <= n; ++i){
        int x;
        cin >> x;
        pos[x] = i;
    }
    int m;
    cin >> m;
    ll vas = 0;
    ll pet = 0;
    for(int i = 0 ;i < m; ++i){
        int x;
        cin >> x;
        vas += pos[x];
        pet += n+1-pos[x];
    }

    cout << vas << " " << pet << endl;

    
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
