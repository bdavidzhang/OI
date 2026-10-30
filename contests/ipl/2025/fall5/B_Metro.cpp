#include<bits/stdc++.h>

using namespace std;

int main(){
    int n,s;
    cin >> n >> s;
    vector<int> a(n),b(n);
    for(int i = 0; i < n; ++i ) cin >> a[i];
    for(int i = 0; i < n; ++i ) cin >> b[i];
    s--;
    if(a[0] == 0){
        cout << "NO" << endl;
        return 0;
    }
    if(a[s] == 1){
        cout << "YES" << endl;
        return 0;
    }
    for(int j = s+1; j < n; ++j){
        if(a[j] == 1 && b[j] == 1 && b[s] == 1){
            cout << "YES" << endl;
            return 0;
        }
    }
    cout << "NO" << endl;

    return 0;
}