#include<bits/stdc++.h>
using namespace std;

int main(){

    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    vector<int> v(n);
    vector<long long> pref(n);
    map<long long, int> freq;
    long long cnt = 0;
    for(int i = 0;i < n; ++i){
        cin >> v[i];
        if(i == 0) pref[i] = v[i];
    }

    for(int i = 0; i < n; ++i){
        if(i == 0) pref[i] = v[i];
        else pref[i] = pref[i-1] + v[i];
        freq[pref[i]]++;
        if(freq[pref[i]] == 2 || pref[i] == 0){
            cnt++; 
            freq.clear();  
            pref[i-1] = 0;
            pref[i] = v[i];
            freq[pref[i]]++;
        } 
    }



    cout << cnt << endl;


    return 0;

}
