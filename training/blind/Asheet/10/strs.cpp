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

    string s1,s2;
    int n = 0;
    cin >> s1 >> s2;
    for(int i =0; i < s1.size(); ++i){
        if(tolower(s1[i]) > tolower(s2[i])) {
            n = 1;
            break;
        }else if(tolower(s1[i]) < tolower(s2[i])){
            n = -1;
            break;
        }
    } 

    cout << n << endl;
    return 0;
}
