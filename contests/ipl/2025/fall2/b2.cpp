#include<bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<pair<int,int>> v(n);
        vector<long long> pre(n);
        for(int i = 0;i < n; ++i){
            cin >> v[i].first;
            v[i].second = i;
        }
        sort(v.begin(),v.end());
        pre[0] = v[0].first;
        for(int i = 1; i <n; ++i){
            pre[i] = pre[i-1] + v[i].first;
        }

        vector<int> ans(n);
        for(int i = 0;i < n; ++i){
            //first find max index that can be absorbed 
            int idx = v[i].second;
            int lo = i;
            int hi = n-1;
            int ans1 = i;
            while(lo <= hi){
                int mid = lo + (hi-lo)/2;
                if(v[i].first == v[mid].first){
                    lo = mid+1;
                    ans1 = mid;
                }else{
                    hi = mid-1;
                }
            }


            lo = ans1;
            hi = n-1;
            int ans2 = ans1;
            while(lo <= hi){
                int mid = lo + (hi-lo)/2;
                if(pre[ans2] >= v[mid].first){
                    ans2 = mid;
                    lo = mid+1;
                }else{
                    hi = mid-1;
                }
            }
            ans[idx] = ans2;
        }
        for(int i =0; i < n; ++i){
            cout << ans[i] << " ";
        }
        cout << endl;
    }


    return 0;
}