#include<bits/stdc++.h>
using namespace std;

int main(){
    string a, b;
    cin >> a >> b;
    map<string,int> memo = {
        {"Ocelot",0},
        {"Serval",1},
        {"Lynx",2}
    };
    if(memo[a] >= memo[b]) cout << "YES" << endl;
    else cout <<"NO" << endl;
    return 0;
}