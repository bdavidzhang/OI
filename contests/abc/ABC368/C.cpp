#include<bits/stdc++.h>
using namespace std;

using vi = vector<int>;
using ll = long long;


int main(){
    int n;
    cin >> n;
    vector<int> h(n);
    ll t = 0;
    for(auto &a : h){
        cin >> a;
        int res = a / 5;
        t += 3*res;
        a = a % 5;
        while(a > 0){
            t++;
            if(t % 3 == 0 )a -= 3;
            else a -= 1;
        }
    }

    cout << t <<endl;


    return 0;
}
