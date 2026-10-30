#include<bits/stdc++.h>

using namespace std;


vector<int> get_digits(int x){
    vector<int> digits;

    while(x != 0){
        digits.push_back(x % 10);
        x /= 10;
    }
    return digits;
}


int main(){
    int n;
    cin >> n;

    vector<int> ways(n+1,1E9);

    ways[0] = 0;

    for(int i = 1; i <= 9; ++i){
        ways[i] = 1;
    }

    for(int i = 10; i <= n; ++i){
        vector<int> digits = get_digits(i);
        for(auto d : digits){
            ways[i] = min(ways[i],ways[i-d]+1);
        }
    }

    cout << ways[n] <<endl;


    return 0;
}
