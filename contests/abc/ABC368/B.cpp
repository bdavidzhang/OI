#include<bits/stdc++.h>
using namespace std;

using vi = vector<int>;
using ll = long long;


int main(){
    int n;
    cin >> n;
    vi a(n);
    for(int i = 0; i <n ; ++i){
        cin>>a[i];         
    }

    ll cnt=0;
        while(true){
        sort(a.begin(),a.end(),greater<int>()); 
        if(a[0] == 0 || a[1] == 0){
                break; 
        }
                a[0]--;
        a[1]--;
        cnt++;
    }
    cout<<cnt<<endl;

    
    

    return 0;
}
