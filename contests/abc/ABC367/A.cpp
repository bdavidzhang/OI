#include<bits/stdc++.h>

using namespace std;

int main(){
    int a, b, c;
    cin >> a >> b >>c;

    vector<bool> time(24,true);
    if(b > c){
        for(int i = b; i <= 23; ++i){
            time[i] = false; 
        }
        for(int i = 0; i <= c; ++i){
            time[i] = false; 
        }
    }else{
        for(int i = b; i <= c; ++i){
            time[i] = false; 
        }
    }
    if(time[a])cout <<"Yes"<<endl;
    else cout <<"No"<<endl; 


    return 0;
}
