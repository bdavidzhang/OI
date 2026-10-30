#include<bits/stdc++.h>
using namespace std;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
   

    int n;
    cin >> n;
    cin.ignore();
    while(n--){
       string s;
       getline(cin, s);
       vector<bool> ab(26,false);
        
      for (char c : s){
            if(isalpha(c)){
                ab[tolower(c) - 'a'] = true; 
            } 
      } 

       string ans = "";
       for(int i = 0; i < 26; ++i){
            if(!ab[i]){
                ans += static_cast<char>('a'+i); 
            } 
       }
       
       if(ans.empty()){
           cout << "pangram" << endl;
       }else{
            cout << "missing " << ans << endl; 
       }

    
    } 


    return 0;
}


