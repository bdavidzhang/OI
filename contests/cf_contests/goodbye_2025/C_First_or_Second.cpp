#include<bits/stdc++.h>
using namespace std;

long long maxop(const vector<int>& A) {
    int n = A.size();
    if (n <= 1) return 0;

    long long S = 0;
    for (int x : A) S += x;

    long long ans = -2e18; 

    ans = max(ans, (long long)A[0] - S);

    long long current_positive_sum = 0;
    
    for (int k = 1; k < n; ++k) {
        long long val = 2LL * A[0] + 2LL * current_positive_sum + A[k] - S;
        ans = max(ans, val);

        if (A[k] > 0) {
            current_positive_sum += A[k];
        }
    }

    return ans;
}
int main(){
    int t;
    cin >> t;
    while(t--){
       int n;
       cin >> n;
       vector<int> v(n);
       for(int i =0 ; i < n; ++i) cin >> v[i];
       cout << maxop(v) << endl;
       
    }

    return 0;
}
