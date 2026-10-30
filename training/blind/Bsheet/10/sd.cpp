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

    string s;
    cin >> s; 
    if(sz(s) == 1){
        cout << 0 << endl;
        return 0;
    }
    ll sum = 0;
    ll cnt = 1;
    for(int i = 0;i < sz(s); ++i){
        sum += int(s[i] - '0');
    }
    ll num = sum; 
    while(num >= 10){
        sum = 0;
        while(num > 0){
            sum += num % 10;
            num /= 10;
        }
        num = sum;
        cnt++;
    }
    cout << cnt << endl; 

    return 0;
}
