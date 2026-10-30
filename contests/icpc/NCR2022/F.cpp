#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, q;
    cin >> n >> q;

    unordered_map<string,int> name;

    for(int i = 0; i < n; ++i){
        string st;
        cin >> st;
        name[st] = i;
    }

    string s1,s2;
    int st,end;
    string out;
    out.reserve(q * 12);

    for(int i = 0 ;i < q; ++i){
        cin >> s1 >> s2;
        st = name[s1],end=name[s2];
        
        out.append(to_string(abs(st-end)-1));
        out.push_back('\n');
    }

    cout << out << endl;

    return 0;
}