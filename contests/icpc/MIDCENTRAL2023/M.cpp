#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    cin >> s;
    int cnt = 1;
    bool ok = true; 
    int i = 0;
    int n = s.size();
    while(i < n){
        // cout << i << endl;
        string cur = to_string(cnt);
        int k = cur.size();
        string tmp = "";
        for(int j = i; j < k+i; ++j) tmp += s[j];
        if(cur == tmp){
            cnt++;
            i += k;
        }else{
            ok = false;
            break;
        }
    }
    if(ok){
        cnt--;
        cout << cnt << endl;
    }else{
        cout << -1 << endl;
    }
    return 0;
}