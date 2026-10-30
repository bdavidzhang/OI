#include<bits/stdc++.h>
using namespace std;


bool solve(vector<int> &a, int cur, int l, int r){
    if(l > r) return true;
    if(a[l] != cur && a[r] != cur) return false;
    if(a[l] == cur) return solve(a,cur+1,l+1,r);
    else return solve(a,cur+1,l,r-1);
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> a(n);
        for(auto &x : a) cin >> x;
        bool flag = solve(a,1,0,n-1);
        if(flag) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}