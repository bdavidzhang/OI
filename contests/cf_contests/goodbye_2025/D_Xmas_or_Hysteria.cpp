#include<bits/stdc++.h>
using namespace std;

struct Elf {
    int val;
    int id;
};

bool cmp(Elf a, Elf b) {
    return a.val < b.val;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while(t--){
     int n, m;
        cin >> n >> m;
        vector<Elf> v(n);
        for(int i = 0; i < n; ++i) {
            cin >> v[i].val;
            v[i].id = i + 1; 
        }
        
        sort(v.begin(), v.end(), cmp);
        
        vector<pair<int,int>> ans;
        bool possible = true;

        if (m == 0) {
            long long current_dmg = v[n-2].val;
            int k = -1; 
            
          
            for (int i = n - 3; i >= 0; --i) {
                current_dmg += v[i].val;
                if (current_dmg >= v[n-1].val) {
                    k = i; 
                    break;
                }
            }

            if (k == -1) {
                possible = false;
            } else {
                for (int i = 0; i < k; ++i) {
                    ans.push_back({v[i].id, v[i+1].id});
                }

                ans.push_back({v[n-1].id, v[n-2].id});

         
                for (int i = k; i <= n - 3; ++i) {
                    ans.push_back({v[i].id, v[n-1].id});
                }
            }

        } else if (m == 1) {
       
            for(int i = 0; i < n - 1; ++i){
                ans.push_back({v[i].id, v[i+1].id});
            }

        } else {
       
            
            if (n < 2 * m) {
                possible = false;
            } else {
            
                int excess = (n - m) - m; 
                
            
                for(int i = 0; i < excess; ++i){
                    ans.push_back({v[i].id, v[i+1].id});
                }
                
             
                int current_fodder = excess;
                for(int i = 0; i < m; ++i){
                    int survivor_idx = n - m + i;
                    int fodder_idx = current_fodder + i;
                    ans.push_back({v[survivor_idx].id, v[fodder_idx].id});
                }
            }
        }

        if (!possible) {
            cout << -1 << "\n";
        } else {
            cout << ans.size() << "\n";
            for(auto p : ans){
                cout << p.first << " " << p.second << "\n";
            }
        }
    }

    return 0;
}
