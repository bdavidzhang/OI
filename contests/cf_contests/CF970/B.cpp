#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<long long>;
using tiii = tuple<int,int,int>;
using vii = vector<vector<int>>;


void solve(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    if(sqrt(n) != int(sqrt(n))){
        cout << "No" << endl;
        return;
    }
    int k = sqrt(n);
    bool flag = true;
    vii g(k,vi(k));
    for(int i = 0; i < k; ++i){
        for(int j = 0; j < k; ++j){
            g[i][j] = s[j+i*k]-'0';
        }
    }

    for (int i = 0; i < k; i++) {
        for (int j = 0; j < k; j++) {
            if((i == 0 || i == k-1) || (j == 0 || j == k-1)) if(g[i][j] != 1) flag = false;
            else{
                if(g[i][j] == 1) flag = false;
            }
        }
    }
    cout << (flag? "Yes" : "No") << endl;

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

