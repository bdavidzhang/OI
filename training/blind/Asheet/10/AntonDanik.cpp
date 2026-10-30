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
    cin >> s;
    ll cnt1 = 0;
    ll cnt2 = 0;
    for(int i = 0;i < n; ++i){
        if(s[i] == 'A') cnt1++;
        else cnt2++;
    }

    if(cnt1 == cnt2) cout << "Friendship" <<endl;
    else if(cnt1 < cnt2) cout << "Danik" << endl;
    else cout << "Anton" << endl;

    return 0;
}
