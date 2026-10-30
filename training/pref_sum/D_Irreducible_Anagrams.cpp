#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin >> s;
    int n = s.size();

    vector<vector<int>> tot(n+1,vector<int>(26,0));

    for(int i = 1; i <= n; ++i){
        for(int j = 0; j < 26; ++j){
            tot[i][j] = tot[i-1][j];
        }
        tot[i][s[i-1]-'a']++;
    }

    int q;
    cin >> q;
    while(q--){
        int l,r;
        cin >> l >> r;
        int cnt = 0;
        for(int j = 0; j < 26; ++j){
            cnt += (-tot[l-1][j] + tot[r][j] > 0);
        }
        if(cnt >= 3 || s[l-1] != s[r-1] || l == r){
            cout << "Yes" << endl;
        }else{
            cout << "No" << endl;
        }
    }
    


    return 0;
}