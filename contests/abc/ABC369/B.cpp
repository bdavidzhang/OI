#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    long long sum = 0;
    cin >> n;
    //init L on first L, R on first R
    
    bool lflag =false, rflag =false;
    int lprev, rprev;
    for(int i = 0; i < n; ++i){
        int a;
        char s;
        cin >> a >> s;
        if(s == 'L'){
            if(lflag){
               sum += abs(lprev-a);   
               lprev = a;
            }else{
                lprev =a;
            } 
            lflag = true;
        }else{
            if(rflag){
                    sum += abs(rprev-a);
                    rprev = a; 
                }else{
                rprev = a; 
                } 
                rflag = true;
            } 
        } 
    

    cout<< sum <<endl;

    return 0;
}
