#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<long long>;
using tiii = tuple<int,int,int>;
using vii = vector<vector<int>>;


void solve(){
   ll a, b;
   cin >> a >> b;

    if(a == 0) cout << ((b%2==0)? "YES" : "NO") << endl;
    else if(b == 0) cout << ((a%2==0)? "YES" : "NO") << endl;
    else if(a == 1) cout << "NO" << endl;
    else if(b == 1) cout << (((a>=2) && a%2 == 0)? "YES" : "NO") << endl;
    else{
        cout << (((a>=2) && a%2 == 0)? "YES" : "NO") << endl;
    }

}


int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--){
        solve();
    }

    return 0;
}

