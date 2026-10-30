#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin >> s;
    int n = int(s.size());
    long long cnt = 0;
    long long ones = 0;
    for(int i = 0; i < n; ++i){
        if(s[i] == '0') cnt += ones;
        else ones++;
    }
  
    cout << (cnt % 3 == 0 ? "Bob" : "Alice") << endl;

    return 0;
}