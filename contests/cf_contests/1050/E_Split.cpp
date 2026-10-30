#include<bits/stdc++.h>
using namespace std;


void solve(){
    int n;
    long long k;
    cin >> n >> k;
    vector<int> a(n);
    vector<int> tot_cnt(n+1,0);

    for(int i = 0; i < n; ++i){
        cin >> a[i];
        tot_cnt[a[i]]++;
    }

    for(int i = 1; i <= n; ++i){
        if (tot_cnt[i] % k != 0){
            cout << 0 << endl;
            return;
        }
    }

    vector<int> target_cnt(n+1,0);
    for(int i = 1;i <= n; ++i){
        target_cnt[i] = tot_cnt[i] / k;
    }

    vector<vector<int>> positions(n+1);
    for(int i =0 ;i < n; ++i){
        positions[a[i]].push_back(i);
    }

    long long ans = 0;
    int max_l_bad = -1;
    vector<int> cur_cnt(n+1,0);

    for(int r = 0; r < n; ++r){
        int v = a[r];
        cur_cnt[v]++;

        if (cur_cnt[v] > target_cnt[v]) {
            int p_idx = cur_cnt[v] - target_cnt[v] - 1;
            int bad_l = positions[v][p_idx];
            
            if (bad_l > max_l_bad) {
                max_l_bad = bad_l;
            }
        }

        ans += (r - max_l_bad);

    }
    cout << ans << endl;


}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;

}