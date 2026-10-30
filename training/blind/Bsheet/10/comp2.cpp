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

    map<char, int> mp;
    mp.insert({'A',0});
    mp.insert({'B',0});
    mp.insert({'C',0});

    for(int i = 0 ; i< 3; ++i){
        string s;
        cin >> s;
        if(s[1] == '>')mp[s[0]]++;
        else mp[s[2]]++;
    }
    
    if(mp['A'] == 1 && mp['B'] == 1 && mp['C'] == 1) cout << "Impossible";
    else{
        for(int i = 0;i < 3; ++i){
            if(mp['A'] == i) cout << 'A';
            else if(mp['B'] == i) cout << 'B';
            else if(mp['C'] == i) cout << 'C';
        }
    }

    cout << endl;



    return 0;
}
