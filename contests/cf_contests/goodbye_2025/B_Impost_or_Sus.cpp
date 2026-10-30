#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        int n = s.size();
        int cnt = 0;
        if(s[0] == 'u'){
            s[0] = 's';
            cnt++;
        }
        if(s[n-1] == 'u'){
            s[n-1] = 's';
            cnt++;
        }
        for(int i = 1;i < n-1; ++i){
            if(s[i] == 's') continue;
            if(s[i] == 'u'){
                if(s[i+1] == 's') continue;
                if(s[i+1] == 'u'){
                    s[i+1] = 's';
                    cnt++;
                }
            }
        }
        cout << cnt << endl;
    }

    return 0;
}