#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<long long>;
using tiii = tuple<int,int,int>;
using vii = vector<vector<int>>;


void solve(){
    string s;
    cin >> s;
    if(s == "101") cout << "NO" << endl;
    else if (s.size() < 3) cout << "NO" << endl;
    else if(s[0] == '1' && s[1] == '0' && s[2] != '0') cout << "YES" << endl;
    else cout << "NO" << endl;
    

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
