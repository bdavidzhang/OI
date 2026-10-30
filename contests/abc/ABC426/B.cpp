#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin >> s;

    map<char,int> freq;
    for(auto & c : s){
        freq[c]++;
    }

    for(auto& pair: freq){
        if(pair.second == 1){
            cout << pair.first << endl;
        }
    }

}