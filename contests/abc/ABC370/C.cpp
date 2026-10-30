#include<bits/stdc++.h>
using namespace std;


int main(){
    string s,t;
    cin >> s >>t;
    vector<string> X;
    int n = s.size();
    vector<int> diff(n);
    for(int i = 0; i < n; ++i){
        diff[i] = s[i] - t[i];
    }


    for(int i = 0; i < n; ++i){
       if(diff[i] > 0){
           s[i] = t[i];
           X.push_back(s);
           diff[i] = 0;  
       }
    }

    for(int i = n-1; i >= 0; --i){
        if(diff[i] < 0){
            s[i] = t[i];
            X.push_back(s);
            diff[i] = 0; 
        } 
    }

    cout << X.size() << endl;
    for(int i = 0; i< X.size(); ++i){
        cout <<X[i] <<endl;  
    } 
    




    return 0;
}
