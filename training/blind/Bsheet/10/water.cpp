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
    int n;
    cin >> n;

    vi v(n+2,1e9); 
    for (int i = 1; i <= n ; i++) {
        cin >> v[i];
    }

    vi L(n+2,0), R(n+2,0);
    for(int j = 1; j <=n; ++j){
        if(v[j] >= v[j-1]) L[j] = L[j-1];
        else L[j] = j;
    }
    for(int j = n; j >= 0; --j){
        if(v[j] >= v[j+1]) R[j] = R[j+1];
        else R[j] = j;
    }

    int tar = 0;
    for(int i = 1; i <= n; ++i){
        tar = max(tar,R[i]-L[i]+1);
    }

    cout << tar << endl;

    return 0;
}
