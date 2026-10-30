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

    int n;
    cin >> n;
    ll cnt = 0;
    for(int i = 0;i < n;++i){
        int sum = 0;
        for(int j = 0;j < 3; ++j){
            int x;
            cin >> x;
            sum += x;
        }
        if(sum >= 2) cnt++;
    }

    cout << cnt << endl;


    return 0;
}
