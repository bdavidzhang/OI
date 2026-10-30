#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<long long>;
using tiii = tuple<int,int,int>;
using vii = vector<vector<int>>;


int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,h;
    cin >>n >> h;
    ll cnt = 0;
    for(int i = 0;i < n; ++i){
        int x;
        cin >> x;
        if(x > h) cnt +=2;
        else cnt++;
    }
    cout << cnt << endl;

    return 0;
}
