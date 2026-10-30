#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, k, m;
    cin >> n >> k >> m;
    vector<int> cnt(n*k);
    for(int i = 0; i < m; ++i){
        int a,b;
        cin >> a >> b;
    }


    for(int i = 0; i < n*k; ++i){
        int a;
        cin >> a;
        cout << ++cnt[a] << " ";
    }
    cout << endl;

    return 0;

}