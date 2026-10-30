#include<bits/stdc++.h>
using namespace std;

int main(){
    
    int n;
    cin >> n;
    string s;
    cin >> s;
    int coffee = 0;
    long long cnt = 0;
    s += "00";
    for(int i =0 ;i < n; ++i){
        if(s[i] == '1'){
            cnt++;
            coffee = 2; 
        }else{
            if(coffee > 0){
                coffee--;
                cnt++; 
            }   
        }
    }

    cout << cnt << endl;
    return 0;

}
