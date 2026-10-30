#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<long long>;
using tiii = tuple<int,int,int>;
using vii = vector<vector<int>>;
#define all(v) ((v).begin()),((v).end())
#define sz(v) ((int)((v).size()))

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);


    int n, a;
    cin >> n >> a;
    vi v(n);
    for(int i = 0;i < n; ++i){
        cin >> v[i];
    }
    vi crim(n);
    vi num(n);
    
    for(int i = 0;i < n; ++i){
        if(v[i] == 1){
            crim[abs(i+1-a)]++;
        }
        num[abs(i+1-a)]++;
    }
    ll cnt = 0;

    for(int i =0;i < n;++i){
        if(crim[i] == num[i]){
            cnt += crim[i];
        }
    }
    cout << cnt << endl; 

    return 0;
}
