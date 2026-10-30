#include<bits/stdc++.h>
using namespace std;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int tt;
    cin >> tt;
    pair<int,int> p1 = {-1,-1}, p2 = {-1,-1};
    while(tt--){
        int n,m;
        cin >> n >> m;
        
        bool seen1 = false;

        for(int i=0;i<n;i++){
            string s;
            cin >> s;
            for (int j=0;j<m;j++){
            if(s[j] == '#'){
                    if(!seen1){
                        p1 = {j,i};
                        seen1 = true;
                    }
                    p2 = {j,i};
                }
            }
        }
    }

    // cout << p1.first << " " << p1.second << endl;
    // cout << p2.first << " " << p2.second << endl;
    cout <<  (p1.second + p2.second) / 2 << " " << p1.first+1 << endl;

    return 0;
}