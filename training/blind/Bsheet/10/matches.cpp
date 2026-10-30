#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<long long>;
using tiii = tuple<int,int,int>;
using vii = vector<vector<int>>;
#define all(v) ((v).begin()),((v).end())
#define sz(v) ((int)((v).size()))


bool great(pair<int,int> a, pair<int,int> b){
    return a.second > b.second;
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m;
    cin >> n >> m;

    vector<pair<int,int>> mat(m);
    for(int i = 0;i < m;++i){
        int a,b;
        cin >> a >> b;
        mat[i] = {a,b}; 
    }
    sort(all(mat), great);

    ll sum =0;
    for(int i = 0;i < m; ++i){
        if(n >= mat[i].first){
            n -= mat[i].first;
            sum += mat[i].second *mat[i].first;
        }else{
            sum += mat[i].second * n;
            break;
        }
        
    }

    cout << sum << endl;
    

    return 0;
}
