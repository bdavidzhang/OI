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
    vi v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        string s;
        cin >> s;
        if(s.size() != v.size()){
            cout << "NO" << endl;
            continue;
        }
        bool flag = true;
        map<int, char> m1;
        map<char, int> m2;
        for (int j = 0; j < n; j++) {
           if(m1.count(s[j]) == 0 && m2.count(v[j]) == 0){
                m1[v[j]] = s[j];
                m2[s[j]] = v[j];
           }else if((m1.count(s[j]) > 0 && m1[v[j]] != s[j]) || (m2.count(v[j]) > 0 && m2[s[j]] != v[j])){

                flag = false;
                break;
           }
        }
        cout << (flag ? "YES" : "NO") << endl; 
        
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
