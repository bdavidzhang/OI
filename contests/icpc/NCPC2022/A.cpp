#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    int x = 0,y = 0;
    for(int i = 0; i < n; ++i){
        string s;
        cin >> s;
        for(char &c : s) if(c == '-') c = ' ';
        stringstream sin(s);

        int a,b;
        sin >> a >> b; 
        if((a + b) % 4 == 1 || (a+b) % 4 == 2)swap(a,b);
         
        if(x > a || y > b || a > 11 || b > 11 || (a == 11 && b == 11) || (x == 11 || y == 11) && (x != a || y != b)){
            cout << "error " << i+1 <<endl;
            return 0; 
        }
    
        x = a;
        y = b; 
    }
    cout << "ok" <<endl;

    return 0;
}
