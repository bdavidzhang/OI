#include<iostream>

using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n,a;
        cin >> n >> a;
        int la = 0;
        int ga = 0;
        for(int i = 0; i < n; ++i){
            int x;
            cin >> x;
            if(x < a) la++;
            else if(x > a)ga++;
        }
        if(ga <= la) cout << a-1 << endl;
        else cout << a+1 << endl;
    }
    return 0;
}