#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<long long>;
using tiii = tuple<int,int,int>;
using vii = vector<vector<int>>;
using ld = long double;
using pii = pair<int,int>;
using vb = vector<bool>;
#define all(v) ((v).begin()),((v).end())
#define sz(v) ((int)((v).size()))
#define fi first
#define se second
#define mp make_pair
#define pb push_back

int gcd(int a, int b){
    if(a < b) swap(a,b);
    if(b == 0) return a;
    return gcd(b, a %b);
} 

void solve(){
    int a, b;
    cin >> a >> b;
    int d = gcd(a,b);
    if(d > 1){
        a /= d;
        b /= d;
    }
    if(a > b+1) cout << "Masha" << endl;
    else if(a == b+1 || b == a+1 || b == a) cout << "Equal" << endl;
    else cout << "Dasha" << endl;
}


int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tk = 1;
    //cin >> tk;
    for(int i = 0; i < tk; ++i){
        solve();
    }
    return 0;
}
//then you will find joy in the LORD
//I will cause you to ride in triumph on
//the heights of the land
//and to feast on the inheritance of your father Jacob
