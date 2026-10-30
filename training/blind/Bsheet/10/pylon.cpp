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
    vll h(n+1);
    ll ans = 0;
    for(int i = 1; i<= n;++i){
        cin >> h[i];
        ans = max(ans,h[i]);
    }
    cout << ans << endl;







    return 0;
}
