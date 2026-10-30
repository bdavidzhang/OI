#include<bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //remember, if I'm doing getline, do cin.ignore() before hand

    int n;
    cin >> n;
    while(n--){
        string s;
        cin >> s;
        
        
        ll L = s.size();
        ll S = 0;
        double rt;
        for(int i = L; i <= L+1000; ++i){

            rt = sqrt(i);
            if(rt - int(rt) == 0){
                S = i;
                break;
            }
        }
        

        vector<vector<char>> grid(rt,vector<char>(rt));

        ll cnt = 0;
        for(int i = 0; i < rt; ++i){
            for(int j = 0; j < rt; ++j){
                if(cnt < L){
                   grid[i][j] = s[cnt];  
                   cnt++;
                }    
                else{
                    grid[i][j] = '*'; 
                }
            } 
        } 
        
        string ans = "";
        for(int j = 0; j < rt; ++j){
            for(int i = rt-1; i >= 0; --i){
                if(grid[i][j] != '*') ans+= grid[i][j]; 
            } 
        }
        
        cout << ans << endl;

    }


    return 0;
}

