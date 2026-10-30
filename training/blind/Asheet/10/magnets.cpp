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
    string s;
    string prev;
    cin >> s;
    int cnt = 1;
    prev = s;
    for(int i = 0;i < n-1; ++i){
        cin >> s;
        if(s[0] == prev[1]) cnt++;
        prev = s;
    }
    cout << cnt << endl;


    return 0;
}
