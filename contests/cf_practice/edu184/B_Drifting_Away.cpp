#include<bits/stdc++.h>
using namespace std;

string solve(){
    string s;
    cin >> s;
    int n = s.size();
    for(int i = 0;i < n; ++i){
        if(s[i] == '*'){
            if(i+1 < n && (s[i+1] == '<' || s[i+1] == '*')) return "-1";
            if(i-1 > -1 && (s[i-1] == '>' || s[i-1] == '*')) return "-1";
        }
        if(s[i] == '>'){
            if(i+1 < n && s[i+1] == '<') return "-1";
        }
        if(s[i] == '<'){
            if(i-1 > -1 && s[i-1] =='>') return "-1";
        }
    }
    int le = 0, ri = 0;
    for(int i = 0; i < n; ++i){
        if(s[i] == '>') break;
        le++;
    }
    for(int i = n-1; i >= 0; --i){
        if(s[i] == '<') break;
        ri++;
    }
    return to_string(max(le,ri));
}


int main(){
    int t;
    cin >> t;
    while(t--){
        cout << solve() << endl;
    }
    return 0;
}