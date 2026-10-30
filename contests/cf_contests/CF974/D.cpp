#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--){
        long long n, d, k;
        cin >> n >> d >> k;
        vector<int> ss(n+1), es(n+1);
        for(int i = 0; i < k; ++i){
            int a,b;
            cin >> a >> b;
            ss[a]++;
            es[b]++; 
        }

        vector<int> overlap(n+1);
        vector<int> val(n);

        
        val[0] = overlap[0];
        long long good = val[0];
        int goodday = 1;
        long long bad = val[0];
        int badday = 1;
        for(int i =1;i < n; ++i){
            val[i] = val[i-1] + overlap[i];
        }
        vector<int> ans(n);
        for(int i = 0; i < d; ++i){
            
        }
        
    }



    return 0;
}
