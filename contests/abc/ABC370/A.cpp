#include<bits/stdc++.h>
using namespace std;

int main(){
    int l,r;
    cin >> l >> r;
    if(l + r == 1){
       if(l == 1)cout<<"Yes"<<endl;
       else cout <<"No"<<endl;    
    }else cout << "Invalid"<<endl;

    return 0;
}
