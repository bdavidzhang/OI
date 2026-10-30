#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> A(n);
        map<int,int> freq;
        for(int i = 0; i < n;++i){
            cin >> A[i];
            freq[A[i]]++;
        }
        if(n == 3){
            set<int> s;
            for(auto &x : A) s.insert(x);
            if(s.size() == 3 ||  accumulate(A.begin(),A.end(),0) - 2*(*s.rbegin()) <= 0) cout << 0 << endl;
            else cout <<  accumulate(A.begin(),A.end(),0)  << endl;
        }else{
        vector<int> L;
        long long ans = 0;
        long long num = 0;
        for(auto p: freq){
            ans += (p.second-p.second%2)*p.first;
            num += (p.second-p.second%2);
            if(p.second%2) L.push_back(p.first);
        }
        sort(L.begin(),L.end());
        reverse(L.begin(),L.end());
        if(L.size() >= 2){
            ans += L[0] + L[1];
            num += 2;
        }
        else if(L.size() == 1){
            ans += L[0];
            num += 1;
        }
        if(num < 3){
            cout << 0 << endl;
        }else{
        cout << ans << endl;
        }
    }
        
    }
    return 0;
}