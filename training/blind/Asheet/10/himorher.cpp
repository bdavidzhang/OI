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

    string s;
    cin >> s;
    set<char> st;
    for(char c : s){
        st.insert(c);
    }

    cout << ((st.size() % 2 == 0) ? "CHAT WITH HER!" : "IGNORE HIM!" )<< endl;



    return 0;
}
