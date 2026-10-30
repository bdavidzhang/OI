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


ll dist(ld a, ld b){
    return (ll) pow(pow(a,2)+pow(b,2),0.5);
}

void solve(){
    ld x1,y1,x2,y2,x3,y3;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    if(dist(x1-x2,y1-y2) == dist(x2-x3,y2-y3) && dist(x3-x1,y3-y1) == dist(x2-x3,y2-y3))
        cout << "Yes" << endl;
    else cout << "No" << endl;
}


int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1; 
    cin >> t;
    for(int i = 0; i < t; ++i){
        solve();
    }
    return 0;
}
//then you will find joy in the LORD
//I will cause you to ride in triumph on
//the heights of the land
//and to feast on the inheritance of your father Jacob
