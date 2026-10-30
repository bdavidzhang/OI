#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        long long x,y;
        cin >> x >> y;
        long long res = x + y;
        long long best = 0;

        for(int bit = 62; bit >= 0; --bit){
            long long mask = 1LL << bit;
            if((res & mask) == 0){
                continue;
            }

            long long cand = best | mask;
            if(cand <= x){
                best = cand;
            }
        }
        cout << res << " " << x - best << endl;
    }
    return 0;
}
