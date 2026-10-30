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
    int cnt = 0;
    for(char c : s){
        if(islower(c)) cnt++;
    }

    if(s.size()-cnt > cnt){
        for(char &c : s){
            c = toupper(c);
        }
    }else{
        for(char &c : s){
            c = tolower(c);
        }

    }

    cout << s << endl;


    return 0;
}
