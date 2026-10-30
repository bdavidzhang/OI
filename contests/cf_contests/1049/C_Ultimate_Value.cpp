#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n; 
    cin >> n;
    vector<long long> a(n);
    long long s = 0;

    for(int i = 0; i < n; ++i){
        cin >> a[i];
        if(i % 2 == 0) s +=a[i];
        else s -= a[i];
    }

    long long mg = 0;

    if(n > 1){
        if (n % 2 != 0) mg = max(mg,(long long)n - 1);
        else mg = max(mg,(long long) n - 2);
    }

    long long minans = LLONG_MAX;
    for (int i = 0;i < n; ++i){
        long long cur = i + 1;
        if (cur % 2 != 0){
            minans = min(minans,cur + 2*a[i]);
        }else{
            if (minans != LLONG_MAX){
                long long r_term = cur + 2 * a[i];
                mg = max(mg, r_term - minans);
            }
        }
    }

    long long maxans = LLONG_MIN;
    for(int i = 0;i < n; ++i){
        long long cur = i+1;
        if (cur % 2 == 0){
            maxans = max(maxans,2*a[i] - cur);
        }else{
            if(maxans != LLONG_MIN){
                long long r_term = 2*a[i] - cur;
                mg = max(mg,maxans - r_term);
            }
        }
    }

    cout << s + mg << endl;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}