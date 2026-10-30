#include<bits/stdc++.h>
using namespace std;

vector<int> ops(int a, int b){
    vector<int> v;
    v.push_back(a+b);
    v.push_back(a-b);
    v.push_back(a*b);
    if(a % b == 0) v.push_back(a/b);
    return v;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> a(3);
    for(auto &x : a) cin >> x;

    vector<int> res;

    for(int x : ops(a[0],a[1])){
        for(int y : ops(x, a[2])){
            res.push_back(y);         
         }
    }

    int mini = 1e9;
    for(int x : res){
        if(x >= 0 && mini > x) mini = x;
    }

    cout << mini << endl;

    
    
    
    

    return 0;
}
