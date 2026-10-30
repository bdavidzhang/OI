#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        long long sum = 0;
        long long cnt = 0;
        int cur;
        for(int i = 0;i < n;++i){
            cin >> cur;
            if(cur >= k) sum += cur;
            else if(cur == 0){
                if(sum != 0){
                    cnt++;
                    sum--; 
                } 
            }
        }    
        cout << cnt << endl;
    
    }



    return 0;
}
