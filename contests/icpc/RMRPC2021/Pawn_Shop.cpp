#include<bits/stdc++.h>

using namespace std;


int main(){
    int n;
    cin >> n;
    vector<int> a(n),b(n);
    for(int i = 0; i < n; ++i) cin >> a[i];
    for(int i = 0; i < n; ++i) cin >> b[i];

    unordered_map<int,int> diff;
    int imb = 0;
    for(int i = 0; i < n; ++i){
        if(diff[a[i]] == 0) imb++;
        else if(diff[a[i]] == -1) imb--; 
        diff[a[i]]++;
        if(diff[b[i]] == 1) imb--;
        else if(diff[b[i]] == 0) imb++;
        diff[b[i]]--;
        cout << b[i] << " ";
        if(imb == 0){
            cout << ((i == n-1) ? "\n" : "# ");
        }
    }

    return 0;
}