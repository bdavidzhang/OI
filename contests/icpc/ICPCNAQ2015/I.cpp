#include<bits/stdc++.h>
using namespace std;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);


    int n;
    cin >>n;
    cin.ignore();
    string ss = "Simon says ";
    while(n--){
        string s;
        getline(cin, s);
        bool flag = true;
        for(int i = 0; i < ss.size(); ++i){
            if(s[i] != ss[i]) flag =false;
        }
        if(flag){
            string ans = "";
            for(int i = ss.size(); i < s.size(); ++i){
                ans += s[i];  
            }
            cout << ans << endl;
        
        }
    }

    return 0;
}

