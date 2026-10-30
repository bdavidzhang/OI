#include<bits/stdc++.h>
using namespace std;

int main(){

    int t; 
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> arr; 
        arr.push_back(-1e9);
        for(int i = 0; i < n; ++i){
            int x; 
            cin >> x;
            if (x == arr.back()); //omit repeats
            else arr.push_back(x);
        }
        long long ans = 0;
        arr.push_back(-1e9);
        for(int i = 1; i < arr.size(); ++i){
            if (arr[i] > arr[i+1] && arr[i] > arr[i-1]) ans++;
        }

        cout << ans << endl;
    }
    return 0;
}







