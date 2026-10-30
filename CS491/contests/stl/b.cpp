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

int pos(int i, int j, vi &v, vi &c){
    if(v[i] < v[j]) return j;
    else{
        if (c[j] == -1) return -1;
        else return pos(i,c[j],v,c);
    }
}

void solve(){
    int n;
    cin >> n;
    vi v(n);
    for (int i = 0; i< n; ++i) cin >> v[i];
    vi c(n);
    c[n-1] = -1;
    for (int i = n-2; i >= 0; --i){
        c[i] = pos(i,i+1,v,c);
    }
    for (int i = 0; i < n-1; ++i){
        if(c[i] != -1) c[i]++;
        cout << c[i] << " ";
    }
    cout << c[n-1] << endl;

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
