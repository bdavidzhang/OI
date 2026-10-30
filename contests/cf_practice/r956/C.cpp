#include<bits/stdc++.h>

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    int t;
    std::cin >>t;
    while(t--){
        int n;
        std::cin >> n;
        std::vector<std::vector<int>> val(3,std::vector<int>(n+1));
        std::vector<std::vector<long long>> pf(3,std::vector<long long>(n+1));

        for (int i = 0;i < 3; ++i){
            for (int j = 1; j <=n; ++j){
                std::cin >> val[i][j];
                pf[i][j] = pf[i][j-1] + val[i][j];
            }
        }
        bool ok = 0;
        std::vector<int> perm = {0,1,2};
        int comp = (pf[perm[0]][n] + 2)/3;
        for (int i =0; i< 6; ++i){
            int cur = 1;
            while (cur <= n && pf[perm[0]][cur] < comp) cur++;
            for (int j = cur+1; j < n; ++j){
                if(pf[perm[1]][j] - pf[perm[1]][cur] >= comp && pf[perm[2]][n] - pf[perm[2]][j] >= comp){
                    std::vector<std::pair<int,int>> ans(3);
                    ans[perm[0]] = {1,cur};
                    ans[perm[1]] = {cur+1,j};
                    ans[perm[2]] = {j+1,n};

                    for (auto x: ans) std::cout<<x.first<<" "<<x.second<<" ";
                    std::cout<<'\n';
                    ok = 1;
                    break;
                }
            } 
            if(ok)break;
            std::next_permutation(perm.begin(),perm.end());

        }
        if(!ok)std::cout<<-1<<'\n';
    }
    return 0;
}








