#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<long long>;
using tiii = tuple<int,int,int>;
using vii = vector<vector<int>>;
#define all(v) ((v).begin()),((v).end())
#define sz(v) ((int)((v).size()))


void solve(vi &v,int n){
    ll cnt = 0;
    for(int i = 0; i< n; ++i){
        for(int j = i+1; j < n; ++j){
            if(gcd(v[i],v[j]) == 1) cnt++;
        }
    }
    double res = double(4*cnt)/(n*n-1);
    if (res == 1) cout << "No estimate for this data set." << endl;
    else cout << sqrt(6/res) << endl;

}


int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    vi v;
    while(cin >> n){
        if(n == 0){
            break;
        }
        v.push_back(n);
    }

    solve(v,v.size());
    

   return 0;
}
//then you will find joy in the LORD
//I will cause you to ride in triumph on
//the heights of the land
//and to feast on the inheritance of your father Jacob
