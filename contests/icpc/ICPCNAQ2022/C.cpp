#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string a,b;
    cin >> a >> b;
    string s = a+b;
    sort(s.begin(),s.end());
    
    cout << s << endl;
    
    return 0;
}
